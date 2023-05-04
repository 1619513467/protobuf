#include "rcfclient.h"
#include "ui_rcfclient.h"

//#include "VrvLogCaller.h"

#include <QStandardItemModel>
#include <QFile>
#include <QDirIterator>

//#include "Jsoncpp/json/json.h"
//#include "crypto/Base64.h"
#include <QTextStream>
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include <QDateTime>
#include <QStringList>
//#include "FileMd5.h"
#include "senddatathread.h"
//#include "uuidhelper.h"

#include <QRegExpValidator>

struct QRcfPrivate
{
    QStandardItemModel*    model;
    QStringList listFile;
    int                    row;
    bool          m_bLoopStatus;
    SendDataThread   *sendDataThread = nullptr;   //线程
    QRcfPrivate(): row(0),m_bLoopStatus(false)
    {
    }
};

RcfClient::RcfClient(QWidget *parent) :
    QDialog(parent),m_pData(new QRcfPrivate),
    ui(new Ui::RcfClient)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(sltSend()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(sltClear()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(sltClear()));
    connect(ui->openFileBtn, SIGNAL(clicked()), this, SLOT(sltOpenFile()));
    connect(ui->openFileDirBtn, SIGNAL(clicked()), this, SLOT(sltOpenFileDir()));
    connect(ui->stopSendBtn, SIGNAL(clicked()), this, SLOT(sltStopSend()));
    connect(this, SIGNAL(sigLoopSend()), this, SLOT(sltLoopSend()));
}

RcfClient::~RcfClient()
{
    m_bStop = true;
    if(m_pData)
    {
        delete m_pData;
        m_pData = NULL;
    }
    Freelib();
    delete ui;
}

void RcfClient::sltLoopSend()
{
    m_pData->m_bLoopStatus =ui->LoopSendCheckBox->isChecked();
    if(m_pData->m_bLoopStatus)
    {
        //循环发送中间暂停一秒
        m_pData->sendDataThread->setSleep();
        m_bStop = false;
        m_pData->sendDataThread->start();
    }
}

void RcfClient::sltSend()
{
    m_bStop = false;
    m_pData->m_bLoopStatus =ui->LoopSendCheckBox->isChecked();
    m_pData->sendDataThread->start();
}

void RcfClient::sltClear()
{
    m_pData->model->removeRows(0,m_pData->model->rowCount());
    m_pData->row = 0;
    m_listFile.clear();
}

void RcfClient::Loadlib()
{
    std::string strDll = "libmiddlercfdll.so";
    /*m_handle = vrv::LoadLibraryByPath(strDll.c_str());
    if (!m_handle)
    {
        VRV_LOG_LOGA(LEVEL_ERROR, "load dll <%s> failed ! %s", strDll.c_str(), strerror(errno));
        return;
    }*/
}

bool RcfClient::LocalSocketClient()
{
   //无总线调用
   /* funPtrCreateUnixLocalSocketClient pFunc
            = (funPtrCreateUnixLocalSocketClient)vrv::GetProcAddressByName(m_handle, strCreateUnixLocalSocketClientFunName);*/
    /*if (!pFunc)
    {
        VRV_LOG_LOGA(LEVEL_ERROR, "get dll symbol <%s> failed ! %s",strCreateUnixLocalSocketClientFunName , strerror(errno));
        return false;
    }

    m_pClientNoBus = pFunc(1, "testServer", "testServer");
    if (m_pClientNoBus == NULL)
    {
         VRV_LOG_LOGA(LEVEL_ERROR, "funPtrCreateUnixLocalSocketClient failed");
         return false;
    }*/
    return true;
}

//#define READ_FILE_BUF 1 * 1024 * 1024

bool RcfClient::SendFileData(int nSpeed)
{
   
    return 0;
}

void RcfClient::Freelib()
{
   
}

int RcfClient::GetCheckMode()
{
    int nMode = 1;
    if (ui->asyncRadioButton->isChecked())
        nMode = 2;
    return nMode;
}

void RcfClient::InitDialog()
{
    m_pData->model = new QStandardItemModel(this);
    ui->treeView->setModel(m_pData->model);//导入模型
    ui->treeView->header()->setDefaultAlignment(Qt::AlignCenter);
   // m_pData->model->setHorizontalHeaderLabels(QStringList()<<"序号"<< "文件名" << "文件路径" << "总大小" << "MD5");     //设置列头

    ui->treeView->setColumnWidth(0, 50);
    ui->treeView->setColumnWidth(1, 200);
    ui->treeView->setColumnWidth(2, 300);
    ui->treeView->setColumnWidth(3, 50);
    ui->treeView->setColumnWidth(4, 200);
   // ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    setAcceptDrops(true);//启用控件的放下操作
    connect(this, SIGNAL(sigAddFileList(QStringList)), this, SLOT(sltAddFileList(QStringList)));

    ui->syncRadioButton->setChecked(true);
    ui->asyncRadioButton->setChecked(false);
    QRegExp regx("[0-9]+$");
    QValidator* validator = new QRegExpValidator(regx, ui->lineEditSpeed);
    ui->lineEditSpeed->setValidator(validator);
}

//void RcfClient::dragEnterEvent(QDragEnterEvent *e)
//{
//    if (e->mimeData()->hasUrls())
//    {
//        e->acceptProposedAction();  // 3. 有拖拽文件时设置接受
//    }
//    //e->acceptProposedAction(); //可以在这个窗口部件上拖放对象
//}
//
//void RcfClient::dropEvent(QDropEvent *event) //释放对方时，执行的操作
//{
//   // QStringList listFile;
//   // for (int i = 0; i < event->mimeData()->urls().size(); ++i)
//   // {
//   //     listFile << event->mimeData()->urls()[i].toLocalFile();
//   // }
//   //if (listFile.empty())
//   //     return;
//   // emit sigAddFileList(listFile);
//}

void RcfClient::sltAddFileList( QStringList list )
{
    //遍历文件
    //QStringList listFile;
    for (int i = 0; i < list.size(); ++i)
    {
        addSubFolderImages(list[i], m_listFile);
        //addSubFolderImages(list[i], listFile);
    }

    //插入到界面上
    QFileInfo fileInfo;
    //for (int i = 0; i < listFile.size(); ++i)
    //{
    //    fileInfo.setFile(listFile[i]);
    //    m_pData->model->setItem(m_pData->row,0,new QStandardItem(QString::number(m_pData->row + 1)));
    //    m_pData->model->setItem(m_pData->row,1,new QStandardItem(fileInfo.fileName()));
    //    m_pData->model->setItem(m_pData->row,2,new QStandardItem(listFile[i]));
    //    //m_pData->model->setItem(m_pData->row,3,new QStandardItem(QString::fromStdString(vrv::FormatSize(fileInfo.size()))));
    //    QString strFileMd5 = "";
    //    //CFileMd5 fMd5;
    //    //fMd5.GetFileMd5(strFileMd5, listFile[i].toStdString(), CHK_FILE_MD5_MODE_COMPLETE ); //精简版MD5
    //    strFileMd5 = GetFileMD5(listFile[i].toStdString().c_str());//GetMd5(listFile[i].toStdString().c_str());
    //    m_pData->model->setItem(m_pData->row,4,new QStandardItem(QString::fromStdString(strFileMd5.toStdString())));
    //    m_pData->row++;
    //}
}

void RcfClient::addSubFolderImages(QString path, QStringList &string_list)
{
    QFileInfo fileInfo;
    fileInfo.setFile(path);
    if (fileInfo.isFile())
    {
        string_list.append(fileInfo.absoluteFilePath());
    }

    if (!fileInfo.isDir() || !fileInfo.exists())
    {
        return;
    }
}

int RcfClient::onAsyncCallNotifyData(const QString &strData, void *pUserData)
{
    if (pUserData == &m_nAsyncCallNoBusFlag)
    {
       // printf("异步调用接受到数据:%s\n", strData.c_str());
    }

    if (pUserData == &m_nAsyncCallWithBusFlag)
    {
         //printf("总线：异步调用有接受到数据:%s\n", strData.c_str());
    }
    return 0;
}



void RcfClient::onAsyncCallFinished(int nRet, void *pUserData)
{
    if (pUserData == &m_nAsyncCallNoBusFlag)
    {
        //printf("异步调用无总线结束返回值:%d\n", nRet);
    }

    if (pUserData == &m_nAsyncCallWithBusFlag)
    {
         //printf("总线：异步调用结束返回值:%d\n", nRet);
    }
}

void RcfClient::sltOpenFileDir()
{
    QString dir = QFileDialog::getExistingDirectory(this,"请选择文件路径","/");
    if (dir.length() != 0)
    {
        QStringList qlist;
        qlist << dir;
        sigAddFileList(qlist);
    }
}

void RcfClient::sltOpenFile()
{
    QString dir = QFileDialog::getOpenFileName(this,"请选择文件","/");
    if (dir.length() != 0)
    {
        QStringList qlist;
        qlist << dir;
        sigAddFileList(qlist);
    }
}

void RcfClient::sltStopSend()
{
   m_bStop = true;
}

void RcfClient::sltSendThread()
{
    QString qsSpeed = ui->lineEditSpeed->text();
    SendFileData(qsSpeed.toInt());
}

QString RcfClient::GetMd5(const char* filePath)
{
    QString strRet = "";
    char cmd[512];
    sprintf(cmd, "md5sum '%s'", filePath);
   // FILE *fp = popen(cmd, "r");
   //// VRV_LOG_LOGA(LEVEL_DEBUG,"cmd <%s>", cmd);
   // if (!fp)
   //     return strRet;

   // int n=0;
   // char szBuf[2][512];
   // char buf[1024] = { 0 };

   // while (fgets(buf, sizeof(buf), fp) != NULL) {
   //     sscanf(buf, "%s%s", szBuf[0],szBuf[1]);
   // }
   // pclose(fp);
   // strRet = szBuf[0];
    return strRet;
}

QString RcfClient::GetFileMD5(std::string strFilePath)
{
    QString strMd5 = "";
    FILE *fp = fopen(strFilePath.c_str(), "rb");
    if (!fp)
    {
       //VRV_LOG_LOGA(LEVEL_DEBUG, "failed <open %s!>",strFilePath.c_str());
       return strMd5;
    }

   // vrv::MD5 md5;
   //// strMd5 = md5.toString();
   // uint64_t nRead = 0;
   // uint64_t dwRead = 0;//已读
   // uint64_t FILE_BUF = 3 * 1024 * 1024;
   // unsigned char *buffer = new unsigned char[FILE_BUF + 1];
   // memset(buffer, 0, FILE_BUF + 1);
   // while(nRead = fread(buffer, 1, FILE_BUF, fp))
   // {
   //     md5.update(buffer,nRead);
   //     dwRead += nRead;//偏移量
   //     memset(buffer, 0, FILE_BUF + 1);
   // }
   // md5.finish();
   // if(fp)
   // {
   //    fclose(fp);
   //    fp = NULL;
   // }
   // if (buffer)
   // {
   //     delete []buffer;
   //     buffer = NULL;
   // }
   // strMd5 = md5.toString();
    return strMd5;
}

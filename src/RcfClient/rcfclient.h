#ifndef RCFCLIENT_H
#define RCFCLIENT_H

#include <QDialog>
#include <QDragEnterEvent>
#include <QUrl>



#include <QThread>



typedef struct stFileInfo
{
    std::string fileName;
    bool bNewFile;
    std::string strContent;
}FILEINFO,*PFILEINFO;

namespace Ui {
class RcfClient;
}

struct QRcfPrivate;

class RcfClient : public QDialog
{
    Q_OBJECT

public:
    explicit RcfClient(QWidget *parent = 0);
    ~RcfClient();

     virtual int onAsyncCallNotifyData(const QString &strData, void *pUserData);
     virtual void onAsyncCallFinished(int nRet, void *pUserData);
signals:
    void sigAddFileList(QStringList);
    void sigLoopSend();
protected slots:
    void sltSend();
    void sltAddFileList(QStringList);
    void sltClear();
    void sltOpenFile();
    void sltOpenFileDir();
    void sltStopSend();
    void sltLoopSend();

protected:
    //void dragEnterEvent(QDragEnterEvent *e);
    //void dropEvent(QDropEvent *event);

protected:
    void Loadlib();
    bool LocalSocketClient();
    bool SendFileData(int nSpeed);
    void Freelib();
    int  GetCheckMode();
    void InitDialog();
    void addSubFolderImages(QString path, QStringList &string_list);
    QString GetMd5(const char* filePath);
    QString GetFileMD5(std::string strFilePath);
public:
   void sltSendThread();
private:
    Ui::RcfClient *ui;
    QRcfPrivate* m_pData = nullptr;

    QStringList m_listFile;
    int m_nAsyncCallNoBusFlag;
    int m_nAsyncCallWithBusFlag;
    bool m_bStop;

    //vrv::Mutex m_Mutex_Member;
    QString m_strGuid;
};

#endif // RCFCLIENT_H

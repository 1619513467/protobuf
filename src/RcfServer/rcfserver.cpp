#include "rcfserver.h"
#include "ui_rcfserver.h"
#include <string>
#include <stdio.h>

#include <QStandardItemModel>
#include <QFile>
#include <QDirIterator>
#include <QDebug>
#include <QDateTime>
#include <sys/stat.h>
#include <QApplication>
#include <QPushButton>

using namespace std;

struct QRcfPrivate
{
    QStandardItemModel*    model;
    QStringList listFile;
    int                    row;
    QRcfPrivate(): row(0)
    {
    }
};

RcfServer::RcfServer(QWidget *parent) :
    QDialog(parent),m_pData(new QRcfPrivate),
    ui(new Ui::RcfServer)
{
    ui->setupUi(this);
    connect(ui->stopBtn, &QPushButton::clicked, this, &RcfServer::sltStop);
    connect(ui->startBtn, &QPushButton::clicked, this, &RcfServer::sltStart);
    connect(ui->clearBtn, &QPushButton::clicked, this, &RcfServer::sltClear);
}

RcfServer::~RcfServer()
{
    delete ui;
}

void RcfServer::Loadlib()
{
    

}

void RcfServer::Freelib()
{

}

void RcfServer::StartServer()
{


}

void RcfServer::sltStart()
{

}

void RcfServer::sltSetData(QString QsFileName, QString QsFilePath, QString QsFilesize, QString QsProgress, QString QsMD5, QString QsTime)
{
}

void RcfServer::sltUpdateRow()
{
}

void RcfServer::sltClear()
{
}

void RcfServer::sltStop()
{
    //ui->statelabel->setText("服务器未开启");
}

void RcfServer::InitDialog()
{
   
}

QString RcfServer::SecondToDay(uint64_t seconds)
{
    return QString();
}

std::string RcfServer::GetMd5(const char* filePath)
{
    return std::string();
}

std::string RcfServer::GetFileMD5(std::string strFilePath)
{
    return std::string();
}

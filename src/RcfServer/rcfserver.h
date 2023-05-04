#ifndef RCFSERVER_H
#define RCFSERVER_H

#include <QDialog>
namespace Ui {
class RcfServer;
}

typedef struct stFileInfo
{
    QString fileName;
    bool bNewFile;
    QString strContent;
}FILEINFO,*PFILEINFO;

struct QRcfPrivate;

class RcfServer : public QDialog
{
    Q_OBJECT

public:
    explicit RcfServer(QWidget *parent = 0);
    ~RcfServer();

    //virtual int onSyncCall(const QString &strData);
    //virtual int onSyncCall(const QString &strInData, QString &strOutData);
    //virtual int onAsyncCall(const QString &strInData);
signals:
    //void sigSetData(QString ,QString ,QString,QString,QString,QString);
    //void sigUpdateRow();
protected slots:
    void sltStop();
    void sltStart();
    void sltSetData(QString QsFileName,QString QsFilePath,QString QsFilesize,QString QsProgress,QString QsMD5,QString QsTime);
    void sltUpdateRow();
    void sltClear();
protected:
    void Loadlib();
    void Freelib();
    void StartServer();
    void InitDialog();
    QString SecondToDay(uint64_t seconds);
    std::string GetMd5(const char* filePath);
    std::string GetFileMD5(std::string strFilePath);
private:
    Ui::RcfServer *ui;

    QRcfPrivate *m_pData = nullptr;
};

#endif // RCFSERVER_H

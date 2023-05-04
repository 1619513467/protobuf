#ifndef SENDDATATHREAD_H
#define SENDDATATHREAD_H

#include <QThread>
#include "rcfclient.h"

class SendDataThread : public QThread
{
public:
    SendDataThread();
    ~SendDataThread();

    void setObj(RcfClient *rcfClient);
    void setSleep();
protected:
    virtual void run();
private:
    RcfClient* pRcfClient;
};

#endif // SENDDATATHREAD_H

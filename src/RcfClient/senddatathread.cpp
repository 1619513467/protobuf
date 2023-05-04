#include "senddatathread.h"

SendDataThread::SendDataThread()
{

}

SendDataThread::~SendDataThread()
{

}

void SendDataThread::setObj(RcfClient *rcfClient)
{
    pRcfClient = rcfClient;
}

void SendDataThread::setSleep()
{
   this->sleep(1);
}

void SendDataThread::run()
{
    pRcfClient->sltSendThread();
}

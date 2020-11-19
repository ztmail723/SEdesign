#include "mythread.h"
#include "mytcpsocket.h"
MyThread::MyThread(qintptr p):
    ptr(p)
{

}

void MyThread::run()
{
    qDebug() << "开始新线程";
    MyTcpSocket* socket = new MyTcpSocket(ptr);
    connect(socket, &MyTcpSocket::disconnected, this, &MyThread::exit);
    this->exec();
}

void MyThread::exit()
{
    qDebug() << "退出线程";
    this->requestInterruption();//请求线程中断
    this->quit();
    this->wait();
}

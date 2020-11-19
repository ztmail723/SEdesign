#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();
protected:
    //Override
    virtual void incomingConnection(qintptr socketDescriptor);
};

#endif // MYTCPSERVER_H

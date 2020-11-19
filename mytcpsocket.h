#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>
#include <QTimer>
#include "messagegenerator.h"
#include "datatasklist.h"
#include "database.h"
#include "entity.h"
class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket(qintptr p);
    void sendMessage(QString msg);
signals:
    void newMessage(QString msg);
public slots:
    void receiveClientMessage(QString msg);
    void onReceiveData();//收到信息
    void onDisconnected();//断开连接
    void handleFunc1011plus();
public:
    void handleFunc1001(QStringList);
    void handleFunc1002(QStringList);
    void handleFunc1003(QStringList);
    void handleFunc1004(QStringList);
    void handleFunc1005(QStringList);
    void handleFunc1006(QStringList);
    void handleFunc1007(QStringList);
    void handleFunc1008(QStringList);
    void handleFunc1009(QStringList);
    void handleFunc1010(QStringList);
    void handleFunc1011(QStringList);
};

#endif // MYTCPSOCKET_HA

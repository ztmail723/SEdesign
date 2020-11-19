#include "mytcpsocket.h"
#include <QDataStream>

MyTcpSocket::MyTcpSocket(qintptr p)
{
    this->setSocketDescriptor(p);
    this->connect(this, &MyTcpSocket::disconnected, this, &MyTcpSocket::onDisconnected); //断开连接的信号与断开连接的槽相连
    this->connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReceiveData); //准备就绪的信号与接收数据的槽相连
    this->connect(this, &MyTcpSocket::newMessage, this, &MyTcpSocket::receiveClientMessage); //接收到新信息
}

void MyTcpSocket::sendMessage(QString msg)
{
    qDebug() << "服务端开始准备发送消息";
    QByteArray arr;
    QDataStream dts(&arr, QIODevice::WriteOnly);
    dts << msg;
    this->write(arr);
    qDebug() << "服务端发送成功";
}

void MyTcpSocket::receiveClientMessage(QString msg)
{
    // 这里处理从客户端接收的数据
    auto msgsplit = msg.split("#");
    int commandID = msgsplit[0].toInt();
    msgsplit.removeFirst();//删除头
    switch (commandID) //根据不同的commandID执行不同的函数
    {
    case 1001:
        handleFunc1001(msgsplit);
        break;
    case 1002:
        handleFunc1002(msgsplit);
        break;
    case 1003:
        handleFunc1003(msgsplit);
        break;
    case 1004:
        handleFunc1004(msgsplit);
        break;
    case 1005:
        handleFunc1005(msgsplit);
        break;
    case 1006:
        handleFunc1006(msgsplit);
        break;
    case 1007:
        handleFunc1007(msgsplit);
        break;
    case 1008:
        handleFunc1008(msgsplit);
        break;
    case 1009:
        handleFunc1009(msgsplit);
        break;
    case 1010:
        handleFunc1010(msgsplit);
        break;
    case 1011:
        handleFunc1011(msgsplit);
        break;
    default:
        break;
    }
}

void MyTcpSocket::onReceiveData()
{
    qDebug() << "服务端开始接受数据";
    QByteArray array = this->readAll();
    QDataStream dts(&array, QIODevice::ReadOnly);
    QString data;
    dts >> data;
    qDebug() << "接受数据：" << data;
    emit newMessage(data);
}

void MyTcpSocket::onDisconnected()
{
    qDebug() << "有一个客户端断开";
}

void MyTcpSocket::handleFunc1011plus()
{
    //这里要把之前计时器从oriUserID到newUserID的转换还原回来
    QString projectID = sender()->property("projectID").toString();
    QString taskType = sender()->property("taskType").toString();
    QString oriUserID = sender()->property("oriUserID").toString();
    QString newUserID = sender()->property("newUserID").toString();
    DatabaseActor::getInstance().taskList.changestaffid(projectID,taskType,oriUserID);
    QString sendMsg = MessageGenerator::t2011(true,"did not recieve");
    sendMessage(sendMsg);
    sender()->deleteLater();
}

void MyTcpSocket::handleFunc1001(QStringList strlist)
{
    QString uid = strlist[0];
    QString pwd = strlist[1];
    QString sendMsg;
    //以下待修改
    QString str = DatabaseActor::getInstance().userList.logInSendMsg(uid, pwd);
    qDebug() << str;
    int sign = str.split("+").at(0).toInt();
    QString type = str.split("+").at(2);
    if (sign != 0)
    {
        sendMsg = MessageGenerator::t2001(sign, uid, type);
    }
    else
    {
        sendMsg = MessageGenerator::t2001(0, "NULL", "NULL");
    }
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1002(QStringList strlist)
{
    QString uid = strlist[0];
    QString sendMsg;
    //以下待修改
    QList<Task> list = DatabaseActor::getInstance().taskList.findUserTask(uid);
    QListIterator<Task> tIterator(list);
    Task temp;
    DataTaskList tList;
    DataTask datatask;
    for (int i = 0; i < list.size(); i++)
    {
        temp = tIterator.next();
        datatask.source = temp.getSource();
        datatask.type = temp.getType();
        datatask.staffid = temp.getStaffId();
        datatask.projectNum = temp.getProjectNum();
        if (temp.getRead() == true)
        {
            datatask.hasRead = 1;
        }
        else
        {
            datatask.hasRead = 0;
        }
        if (temp.getIsFinished() == true)
        {
            datatask.hasFinished = 1;
        }
        else
        {
            datatask.hasFinished = 0;
        }
        tList.myList.append(datatask);
    }
//    DataTask t1;
//    t1.projectNum = "111";
//    t1.type = "A";
//    t1.source = "test";
//    t1.staffid = "A";
//    tList.myList.append(t1);
    sendMsg = MessageGenerator::t2002(tList);
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1003(QStringList strlist)
{
    QString uid = strlist[0];
    QString sendMsg;
    //以下待修改
    QList<Task> list = DatabaseActor::getInstance().taskList.findUserTask(uid);
    QListIterator<Task> tIterator(list);
    Task temp;
    DataTaskList tList;
    DataTask datatask;
    for (int i = 0; i < list.size(); i++)
    {
        temp = tIterator.next();
        datatask.source = temp.getSource();
        datatask.type = temp.getType();
        datatask.staffid = temp.getStaffId();
        datatask.projectNum = temp.getProjectNum();
        if (temp.getRead() == true)
        {
            datatask.hasRead = 1;
        }
        else
        {
            datatask.hasRead = 0;
        }
        if (temp.getIsFinished() == true)
        {
            datatask.hasFinished = 1;
        }
        else
        {
            datatask.hasFinished = 0;
        }
        tList.myList.append(datatask);
    }
    sendMsg = MessageGenerator::t2003(tList);
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1004(QStringList strlist)
{
    QString uid = strlist[0];
    QString type = strlist[1];
    QString sendMsg;
    QList<User> list = DatabaseActor::getInstance().userList.findRecieveUser(uid);
    QListIterator<User> rIterator(list);
    User temp;
    DataStaffList rList;
    DataStaff datastaff;
    for (int i = 0; i < list.size(); i++)
    {
        temp = rIterator.next();
        datastaff.type = temp.getType();
        datastaff.staffid = temp.getUserId();
        rList.slist.append(datastaff);
    }
    sendMsg = MessageGenerator::t2004(rList);
    qDebug() << sendMsg;
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1005(QStringList strlist)
{
    QString uid = strlist[0];
    QString pid = strlist[1];
    QString type = strlist[2];
    QString sendMsg;
    QString msg;

    bool flag = false;
    flag = DatabaseActor::getInstance().taskList.endATask(uid, pid, type);
    if (flag)
    {
        msg = "submitted successfully";
        sendMsg = MessageGenerator::t2005(true, msg);
    }
    else
    {
        msg = "error";
        sendMsg = MessageGenerator::t2005(false, msg);
    }
    qDebug() << sendMsg;
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1006(QStringList strlist)
{
    QString uid = strlist[0];
    QString sendMsg;
    Project project;
    QList<Project> projectList = DatabaseActor::getInstance().projectList.allProject();
    DataProjectList dplist;
    DataProject dataproject;
    QListIterator<Project> pIterator(projectList);

    while(pIterator.hasNext()){
        //qDebug() <<"*****************";
        project = pIterator.next();
        for (int i = 0; i < 3; i++) {
            dataproject.tasks[i].type = project.getTask()[i].getType();
            dataproject.tasks[i].source = project.getTask()[i].getSource();
            dataproject.tasks[i].hasRead = project.getTask()[i].getRead();
            dataproject.tasks[i].staffid = project.getTask()[i].getStaffId();
            dataproject.tasks[i].projectNum = project.getTask()[i].getProjectNum();
            dataproject.tasks[i].hasFinished = project.getTask()[i].getIsFinished();
            //qDebug() << project.getTask()[i].getID();
        }
        dataproject.projectNum = project.getProjectNum();

        dplist.pList.append(dataproject);
    }
    sendMsg = MessageGenerator::t2006(dplist);
    qDebug() << sendMsg;
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1007(QStringList strlist)
{
    QString type = strlist[0];
    QString sendMsg;
    QList<User> list = DatabaseActor::getInstance().userList.findATypeUser(type);
    QListIterator<User> rIterator(list);
    User temp;
    DataStaffList uList;
    DataStaff datastaff;
    for (int i = 0; i < list.size(); i++)
    {
        temp = rIterator.next();
        datastaff.type = temp.getType();
        datastaff.staffid = temp.getUserId();
        uList.slist.append(datastaff);
    }
    sendMsg = MessageGenerator::t2007(uList);
    qDebug() << sendMsg;
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1008(QStringList strlist)
{
    auto project = DataProject(strlist[0]);
    QString sendMsg;
    Project _project;
    _project.setProjectNum(project.projectNum);
    for(int i = 0; i < 3; i++){
        Task task;
        task.setID(project.tasks[i].type + "0" + project.tasks[i].projectNum);
        //qDebug() << "&&&&&&&&&&&&&&&&&&" <<task.getID();
        task.setRead(project.tasks[i].hasRead);
        task.setType(project.tasks[i].type);
        task.setStaff(project.tasks[i].staffid);
        task.setSource("admin");
        task.setIsFinished(project.tasks[i].hasFinished);
        task.setProjectNum(project.tasks[i].projectNum);
        _project.setTask(task);
    }

    DatabaseActor::getInstance().projectList.add(_project);
    DatabaseActor::getInstance().taskList.add(_project.getTask()[0]);
    DatabaseActor::getInstance().taskList.add(_project.getTask()[1]);
    DatabaseActor::getInstance().taskList.add(_project.getTask()[2]);
    //QList<Project> i = DatabaseActor::getInstance().projectList.allProject();
    DatabaseActor::getInstance().insertAProject(_project);

    sendMsg = MessageGenerator::t2008(true,"created successfully");
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1009(QStringList strlist)
{
    QString pid = strlist[0];
    QString sendMsg;
    DatabaseActor::getInstance().deleteAProject(pid);
    sendMsg = MessageGenerator::t2009(true,"deleted successfully");
    sendMessage(sendMsg);
}
void MyTcpSocket::handleFunc1010(QStringList strlist)
{
    QString pid = strlist[0];
    auto project = DataProject(strlist[1]);
    QString sendMsg;
    Project _project;
    _project.setProjectNum(pid);
    for (int i = 0; i < 3; i++) {
        Task task;
        task.setID(project.tasks[i].type + "0" +project.tasks[i].projectNum);
        task.setRead(project.tasks[i].hasRead);
        task.setType(project.tasks[i].type);
        task.setStaff(project.tasks[i].staffid);
        task.setSource(project.tasks[i].source);
        task.setIsFinished(project.tasks[i].hasFinished);
        task.setProjectNum(project.tasks[i].projectNum);
        _project.setTask(task);
    }
    DatabaseActor::getInstance().projectList.makeProjectNew(pid, _project);
    sendMsg = MessageGenerator::t2010(true,"restart successfully");
    sendMessage(sendMsg);
//
}
void MyTcpSocket::handleFunc1011(QStringList strlist)
{
    QString projectID = strlist[0];
    QString taskType = strlist[1];
    QString oriUserID = strlist[2];
    QString newUserID = strlist[3];
    int time = strlist[4].toInt();
    DatabaseActor::getInstance().taskList.changestaffid(projectID,taskType,newUserID,time);
    QString sendMsg = MessageGenerator::t2011(true,"transfer successfully");
    sendMessage(sendMsg);
    QTimer* timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &MyTcpSocket::handleFunc1011plus);
    timer->setProperty("projectID", projectID);
    timer->setProperty("taskType", taskType);
    timer->setProperty("oriUserID", oriUserID);
    timer->setProperty("newUserID", newUserID);
    timer->start(time);
}

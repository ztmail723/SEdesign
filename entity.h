#ifndef ENTITY_H
#define ENTITY_H
#include <QString>
#include <QObject>
#include <QDebug>

class Task
{
public:
    Task();
    Task(QString, QString, QString, QString, QString);
    void setProjectNum(QString);//设置任务所对应的工程号
    void setType(QString);//设置任务类型
    void setSource(QString);//设置
    void setStaff(QString);
    void setIsFinished(bool);
    void setRead(bool);
    void setID(QString);
    const QString getID();
    QString getStaffId();
    QString getSource();
    QString getType();
    QString getProjectNum();
    bool getIsFinished();
    bool getRead();

private:
    QString ID;//任务号
    QString projectNum; //所属项目号   
    QString type; //任务类型
    QString source; //任务来源（"admin" / 转派员工id + 时限）
    QString staffid; //负责员工的id
    int read; //已读未读标记
    bool IsFinished;//项目是否完成（“true”/“false”）
};

class Project
{
public:
    Project();

    void setProjectNum(QString); //设置项目号
    void setTask(Task); //设置任务
    QString getProjectNum();   
    QList<Task> getTask();

private:
    int flag;
    QString projectNum; //项目号
    Task tasks[3]; //项目里的任务
};

class Message
{
public:
    Message();
    Message(bool,QString,QString,QString,QString);
    void setFlag(bool);
    void setSenderId(QString);
    void setRecipentId(QString);
    void setID(QString);
    void setContent(QString);
    bool getFlag();
    QString getSenderId();
    QString getRecipentId();
    QString getID();
    QString getContent();

private:
    bool flag;
    QString sender;
    QString recipent;
    QString ID;
    QString content;
};

class User
{
public:
    User();
    User(QString,QString,QString);
    void setUserId(QString);
    void setPassword(QString);
    void setType(QString);
    void setLimit(QString);
    QString getUserId();
    QString getIPassword();
    QString getType();
    QString getLimit();

private:
    QString userId; //员工id
    QString password; //密码
    QString type; //员工类型
    QString limit; //员工权限
};

class TaskList : public QObject
{
    Q_OBJECT

public:
    void add(Task t); //添加一个项目
    QList<Task> findUserTask(QString name);
    bool endATask(QString id, QString pid, QString type);
    void changestaffid(QString pid, QString type, QString staffid, int time);
    void changestaffid(QString pid, QString type, QString staffid);
public:
    QList<Task> list;
};

class ProjectList : public QObject
{
    Q_OBJECT
public:
    void add(Project);
    QList<Project> allProject();
    void makeProjectNew(QString pid, Project project);

public:
    QList<Project> list;
};

class UserList : public QObject
{
    Q_OBJECT
public:
    void add(User);
    QString logInSendMsg(QString name, QString psw);//1001
    QList<User> findRecieveUser(QString type);//1004
    QList<User> findATypeUser(QString type);//1007
public:
    QList<User> list;

};

class MessageList : public QObject
{
    Q_OBJECT
public:
    void add(Message);

public:
    QList<Message> list;
};

#endif // ENTITY_H

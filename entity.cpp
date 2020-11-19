#include "entity.h"

Task::Task(){

}

Task::Task(QString _projectNum, QString _type, QString _source, QString _ID, QString _staffid){
    this->projectNum = _projectNum;
    this->type = _type;
    this->source = _source;
    this->ID = _ID;
    this->staffid= _staffid;
}

void Task::setProjectNum(QString _projectNum){
    this->projectNum = _projectNum;
}

void Task::setType(QString _type){
    this->type = _type;
}

void Task::setSource(QString _source){
    this->source = _source;
}

void Task::setStaff(QString _staffid){
    this->staffid = _staffid;
}

void Task::setIsFinished(bool _isFinished){
    this->IsFinished = _isFinished;


    this->read = true;
}

void Task::setRead(bool _read){
    this->read = _read;
}

void Task::setID(QString _ID){
    this->ID = _ID;
}

const QString Task::getID(){
    return this->ID;
}

QString Task::getStaffId(){
    return this->staffid;
}

QString Task::getType(){
    return this->type;
}

QString Task::getSource(){
    return this->source;
}

QString Task::getProjectNum(){
    return this->projectNum;
}

bool Task::getRead(){
    return this->read;
}

bool Task::getIsFinished(){
    return this->IsFinished;
}

void TaskList::add(Task t){
    this->list.append(t);
}

QList<Task> TaskList::findUserTask(QString name){
    QListIterator<Task> i(list);
    QList<Task> tempList;
    Task temp;
    while(i.hasNext()){
        temp = i.next();
        if(temp.getStaffId() == name){
            tempList.append(temp);
        }
    }
    return tempList;
}

bool TaskList::endATask(QString id, QString pid, QString type){
    QListIterator<Task> i(list);
    Task temp;
    int j = 0;
    while(i.hasNext()){
        temp = i.next();
        if(temp.getType() == type && temp.getProjectNum() == pid){
            list[j].setIsFinished(true);
            //qDebug() << "***************" << list[j].getID() <<"////////////";
            return true;
        }
        j++;
    }
    return false;
}

void TaskList::changestaffid(QString pid, QString type, QString staffid, int time){
    QListIterator<Task> i(list);
    Task temp;
    int j = 0;
    while(i.hasNext()){
        temp = i.next();
        if(temp.getType() == type && temp.getProjectNum() == pid){
            list[j].setSource(list[j].getStaffId() + "(" + QString::number(time/1000) + "s)");
            list[j].setStaff(staffid);
        }
        j++;
    }
}

void TaskList::changestaffid(QString pid, QString type, QString staffid){
    QListIterator<Task> i(list);
    Task temp;
    int j = 0;
    while(i.hasNext()){
        temp = i.next();
        if(temp.getType() == type && temp.getProjectNum() == pid){
            list[j].setSource(list[j].getStaffId());
            list[j].setStaff(staffid);
        }
        j++;
    }
}

Message::Message(){

}

Message::Message(bool _flag, QString _sender, QString _recipent, QString _ID, QString _content){
    this->flag = _flag;
    this->sender = _sender;
    this->recipent = _recipent;
    this->ID = _ID;
    this->content = _content;
}

void Message::setFlag(bool _flag){
    this->flag = _flag;
}

void Message::setSenderId(QString _sender){
    this->sender = _sender;
}

void Message::setRecipentId(QString _recipent){
    this->recipent = _recipent;
}

void Message::setID(QString _ID){
    this->ID = _ID;
}

void Message::setContent(QString _content){
    this->content = _content;
}

bool Message::getFlag(){
    return this->flag;
}

QString Message::getSenderId(){
    return this->sender;
}

QString Message::getRecipentId(){
    return this->recipent;
}

QString Message::getID(){
    return this->ID;
}

QString Message::getContent(){
    return this->content;
}

void MessageList::add(Message _msg){
    this->list.append(_msg);
}

User::User(){

}

User::User(QString _userId, QString _password, QString _type){
    this->userId = _userId;
    this->password = _password;
    this->type = _type;
}

void User::setUserId(QString _userId){
    this->userId = _userId;
}

void User::setPassword(QString _password){
    this->password = _password;
}

void User::setType(QString _type){
    this->type = _type;
}

void User::setLimit(QString _Limit){
    this->limit = _Limit;
}

QString User::getUserId(){
    return this->userId;
}

QString User::getIPassword(){
    return this->password;
}

QString User::getType(){
    return this->type;
}

QString User::getLimit(){
    return this->limit;
}

void UserList::add(User user){
    list.append(user);
}

QString UserList::logInSendMsg(QString name, QString psw){
    QListIterator<User> i(list);
    while(i.hasNext()){
        User temp = i.next();
        if(temp.getUserId() == name){
            if(temp.getIPassword() == psw){
                if(temp.getLimit() == "1"){
                    return "2+" + name + "+";
                }
                else {
                    return "1+" + name + "+" + temp.getType();
                }
            }
            else {
                return "0++";
            }
        }
    }
    return "0++";
}

QList<User> UserList::findRecieveUser(QString uid){
    QListIterator<User> i(list);
    QList<User> rUserList;
    QString type;
    QString limit;
    while(i.hasNext()){
        User temp = i.next();
        if(temp.getUserId() == uid){
            type = temp.getType();
            limit = temp.getLimit();
        }
    }
    i.toFront();
    while(i.hasNext()){
        User temp = i.next();
        if(temp.getType() == type && temp.getLimit() == limit){
            rUserList.append(temp);
        }
    }
    return rUserList;
}

QList<User> UserList::findATypeUser(QString type){
    QListIterator<User> i(list);
    QList<User> rUserList;
    while(i.hasNext()){
        User temp = i.next();
        if(temp.getType() == type && temp.getLimit() != "1"){
            rUserList.append(temp);
        }
    }
    return rUserList;
}

Project::Project(){
    tasks[0].setID(nullptr);
    tasks[1].setID(nullptr);
    tasks[2].setID(nullptr);
    flag = 0;
}

void Project::setTask(Task _task){
    tasks[flag] = _task;
    flag++;
}

void Project::setProjectNum(QString _projectNum){
    this->projectNum = _projectNum;
}

QString Project::getProjectNum(){
    return this->projectNum;
}

QList<Task> Project::getTask(){
    QList<Task> tasklist;
    tasklist.append(this->tasks[0]);
    tasklist.append(this->tasks[1]);
    tasklist.append(this->tasks[2]);
    return tasklist;
}

QList<Project> ProjectList::allProject(){

    QListIterator<Project> i(list);
    Project temp;
    while(i.hasNext()){
        temp = i.next();
        //qDebug() <<"==============="<<temp.getProjectNum()<<temp.getTask()[0].getID()<<temp.getTask()[1].getID()<<temp.getTask()[2].getID();
    }
    return list;
}

void ProjectList::makeProjectNew(QString pid, Project project){
    QListIterator<Project> i(list);
    Project temp;
    int j = 0;
    while(i.hasNext()){
        temp = i.next();
        if(temp.getProjectNum() == pid){
            list[j] = project;
        }
        j++;
    }
}

void ProjectList::add(Project p){
    this->list.append(p);
}


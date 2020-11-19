#include"database.h"

DatabaseActor::DatabaseActor()
{
    connect();
    dataTakeOut();
}

DatabaseActor::~DatabaseActor(){
    databaseUpdate();
}

DatabaseActor& DatabaseActor::getInstance(){
    static DatabaseActor databaseActor;
    return  databaseActor;
}

void DatabaseActor::connect(){

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("task.db");
    if (!DB.open())
    {
        qDebug() << "Error: Failed to connect database." << DB.lastError();
    }
    else
    {
        qDebug() << "Succeed to connect database." ;
    }
}

void DatabaseActor::dataTakeOut(){

    setTaskList();
    setMessageList();
    setUserList();
    setProjectList();
}

void DatabaseActor::setTaskList(){
    //taskList.list = NULL;
    for (int i = 0; i < taskList.list.size(); i++) {
        taskList.list.removeAt(i);
    }
    QSqlQuery taskQuery;
    Task task;
    QString select_sql = "select ID, Type, Source, Staff_ID, Read, IsFinished, Project_ID from task";
    if(!taskQuery.exec(select_sql))
    {
        qDebug()<<taskQuery.lastError();
    }
    else
    {
        while(taskQuery.next())
        {
            QString ID = taskQuery.value(0).toString();
            QString Type = taskQuery.value(1).toString();
            QString source = taskQuery.value(2).toString();
            QString staff_ID = taskQuery.value(3).toString();
            bool read = taskQuery.value(4).toBool();
            bool isFinished = taskQuery.value(5).toBool();
            QString project_ID = taskQuery.value(6).toString();
            //QString _projectNum, QString _type, QString _source, QString _ID, QString _staffid
            task.setID(ID);
            task.setType(Type);
            task.setSource(source);
            task.setStaff(staff_ID);
            task.setIsFinished(isFinished);
            task.setRead(read);
            task.setProjectNum(project_ID);
            taskList.add(task);
        }
    }
}

void DatabaseActor::setUserList(){
    QSqlQuery UserQuery;
    User user;
    QString select_sql = "select ID, type, limit1, Password from User";
    if(!UserQuery.exec(select_sql))
    {
        qDebug()<<UserQuery.lastError();
    }
    else
    {
        while(UserQuery.next())
        {
            QString ID = UserQuery.value(0).toString();
            QString Type = UserQuery.value(1).toString();
            QString Limit = UserQuery.value(2).toString();
            QString Password = UserQuery.value(3).toString();
            user.setUserId(ID);
            user.setType(Type);
            user.setPassword(Password);
            user.setLimit(Limit);
            //qDebug() << ID << Type << Limit << Password;
            //user->setLimit(Limit);
            //QString _userId, QString _password, QString _type
            userList.add(user);
        }
    }
}

void DatabaseActor::setProjectList(){
    QSqlQuery ProjectQuery;

    QString select_sql = "select ID, task_id_1, task_id_2, task_id_3 from Project";
    if(!ProjectQuery.exec(select_sql))
    {
        qDebug()<<ProjectQuery.lastError();
    }
    else
    {
        while(ProjectQuery.next())
        {
            Project project;
            QString ID = ProjectQuery.value(0).toString();
            QString task_id_1 = ProjectQuery.value(1).toString();
            QString task_id_2 = ProjectQuery.value(2).toString();
            QString task_id_3 = ProjectQuery.value(3).toString();
            //qDebug() << "////////" <<task_id_1 << task_id_2 << task_id_3;
            QListIterator<Task> i(taskList.list);
            while (i.hasNext()) {
               Task temp = i.next();
                if(temp.getID() == task_id_1) {
                    project.setTask(temp);
                    //qDebug() <<temp.getID();
                }else if(temp.getID() == task_id_3){
                    project.setTask(temp);
                    //qDebug() <<temp.getID();
                }else if(temp.getID() == task_id_2){
                    project.setTask(temp);
                    //qDebug() <<temp.getID();
                }
            }
            project.setProjectNum(ID);
            //qDebug() << "**********" <<project.getProjectNum();
            projectList.add(project);
        }
    }
}

void DatabaseActor::setMessageList(){

    QSqlQuery MessageQuery;
    Message message;
    QString select_sql = "select ID, Flag, Sender, Recipient, Content from MSG";
    if(!MessageQuery.exec(select_sql))
    {
        qDebug()<<MessageQuery.lastError();
    }
    else
    {
        while(MessageQuery.next())
        {
            QString ID = MessageQuery.value(0).toString();
            bool Flag = MessageQuery.value(1).toBool();
            QString Sender = MessageQuery.value(2).toString();
            QString Recipient = MessageQuery.value(3).toString();
            QString Content = MessageQuery.value(4).toString();
            message.setID(ID);
            message.setFlag(Flag);
            message.setContent(Content);
            message.setSenderId(Sender);
            message.setRecipentId(Recipient);
            messageList.add(message);
        }
    }
}

void DatabaseActor::databaseUpdate(){
    connect();
    updateTaskTable();
    updateMessageTable();
    updateProjectTable();
    //insertTaskTable();
    //insertProjectTable();
    //insertMessageTable();
}

void DatabaseActor::updateTaskTable(){
    QSqlQuery TaskQuery;
    Task task;
    QListIterator<Task> i(taskList.list);
    QString update_sql = "update task set Type = :Type, Source = :Source, Staff_ID = :Staff_ID, Read = :Read, IsFinished = :IsFinished, Project_ID = :Project_ID where ID = :ID";
    while(i.hasNext()){
        TaskQuery.prepare(update_sql);
        task = i.next();
        //qDebug() << task.getID() <<"**" << task.getIsFinished();
        TaskQuery.bindValue(":Type", task.getType());
        TaskQuery.bindValue(":Source", task.getSource());
        TaskQuery.bindValue(":Staff_ID", task.getStaffId());
        TaskQuery.bindValue(":Read",task.getRead());
        TaskQuery.bindValue(":IsFinished", task.getIsFinished());
        TaskQuery.bindValue(":Project_ID",task.getProjectNum());
        TaskQuery.bindValue(":ID",task.getID());
        TaskQuery.exec();
    }
}

void DatabaseActor::updateMessageTable(){
    QSqlQuery MessageQuery;
    Message message;
    QListIterator<Message> i(messageList.list);
    QString update_sql = "update MSG set Flag = :Flag, Sender = :Sender, Recipient = :Recipient, Content = :Content where ID = :ID";
    while(i.hasNext()){
        MessageQuery.prepare(update_sql);
        message = i.next();
        MessageQuery.bindValue(":Flag", message.getFlag());
        MessageQuery.bindValue(":Sender", message.getSenderId());
        MessageQuery.bindValue(":Recipient", message.getRecipentId());
        MessageQuery.bindValue(":Content",message.getContent());
        MessageQuery.bindValue(":ID",message.getID());
        MessageQuery.exec();
    }
}

void DatabaseActor::updateProjectTable(){
    QSqlQuery ProjectQuery(DB);
    Project project;
    Task task;
    QListIterator<Project> i(projectList.list);
    QString update_sql = "update PROJECT set task_id_1 = :task_id_1, task_id_2 = :task_id_2, task_id_3 = :task_id_3 where ID = :ID";
    while(i.hasNext()){
        ProjectQuery.prepare(update_sql);
        project = i.next();
        QListIterator<Task> j(project.getTask());
        task = j.next();
        ProjectQuery.bindValue(":task_id_1", task.getID());
        task = j.next();
        ProjectQuery.bindValue(":task_id_2", task.getID());
        task = j.next();
        ProjectQuery.bindValue(":task_id_3", task.getID());
        ProjectQuery.bindValue(":ID", project.getProjectNum());
        ProjectQuery.exec();
    }
}

void DatabaseActor::insertTaskTable(){
    QSqlQuery TaskQuery;
    Task task;
    QListIterator<Task> i(newTaskList.list);
    QString insert_sql = "insert into task values (?, ?, ?, ?, ?, ?, ?)";
    while(i.hasNext()){
        task = i.next();
        TaskQuery.prepare(insert_sql);
        TaskQuery.addBindValue(task.getID());
        TaskQuery.addBindValue(task.getType());
        TaskQuery.addBindValue(task.getSource());
        TaskQuery.addBindValue(task.getStaffId());
        TaskQuery.addBindValue(task.getRead());
        TaskQuery.addBindValue(task.getIsFinished());
        TaskQuery.addBindValue(task.getProjectNum());
        TaskQuery.exec();
    }
}

void DatabaseActor::insertProjectTable(){
    QSqlQuery ProjectQuery;
    Project project;
    Task task;
    QListIterator<Project> i(newProjectList.list);
    QString update_sql = "insert into PROJECT values (?, ?, ?, ?)";
    while(i.hasNext()){
        ProjectQuery.prepare(update_sql);
        project = i.next();
        QListIterator<Task> j(project.getTask());
        ProjectQuery.addBindValue(project.getProjectNum());
        task = j.next();
        ProjectQuery.addBindValue(task.getID());
        task = j.next();
        ProjectQuery.addBindValue(task.getID());
        task = j.next();
        ProjectQuery.addBindValue(task.getID());
        ProjectQuery.exec();
    }
}

void DatabaseActor::insertMessageTable(){
    QSqlQuery MessageQuery;
    Message message;
    QListIterator<Message> i(newMessageList.list);
    QString update_sql = "insert into MSG values (?, ?, ?, ?, ?)";
    while(i.hasNext()){
        MessageQuery.prepare(update_sql);
        message = i.next();
        MessageQuery.addBindValue(message.getID());
         MessageQuery.addBindValue(message.getFlag());
        MessageQuery.addBindValue(message.getSenderId());
        MessageQuery.addBindValue(message.getRecipentId());
        MessageQuery.addBindValue(message.getContent());
        MessageQuery.exec();
    }
}

void DatabaseActor::insertAProject(Project project){
    QSqlQuery ProjectQuery;
    Task task;
    QString insert_sql_project = "insert into PROJECT values (?, ?, ?, ?)";
    ProjectQuery.prepare(insert_sql_project);
    ProjectQuery.addBindValue(project.getProjectNum());
    ProjectQuery.addBindValue(project.getTask()[0].getID());
    ProjectQuery.addBindValue(project.getTask()[1].getID());
    ProjectQuery.addBindValue(project.getTask()[2].getID());
    ProjectQuery.exec();
    QSqlQuery TaskQuery;
    QListIterator<Task> i(project.getTask());
    QString insert_sql_task = "insert into task values (?, ?, ?, ?, ?, ?, ?)";
    while(i.hasNext()){
        task = i.next();
        TaskQuery.prepare(insert_sql_task);
        TaskQuery.addBindValue(task.getID());
        TaskQuery.addBindValue(task.getType());
        TaskQuery.addBindValue(task.getSource());
        TaskQuery.addBindValue(task.getStaffId());
        TaskQuery.addBindValue(task.getRead());
        TaskQuery.addBindValue(task.getIsFinished());
        TaskQuery.addBindValue(task.getProjectNum());
        TaskQuery.exec();
    }
}

void DatabaseActor::deleteAProject(QString id){
    QSqlQuery ProjectQuery;
    QString delete_sql = "delete from PROJECT where ID = ?";
    ProjectQuery.prepare(delete_sql);
    ProjectQuery.addBindValue(id);
    ProjectQuery.exec();
    QSqlQuery TaskQuery;
    QString delete_sql_task = "delete from task where ID = ?";
    Task task;
    Project project;
    int i = 0;
    QListIterator<Task> tIterator(taskList.list);
    while(tIterator.hasNext()){
        task = tIterator.next();
        if(task.getProjectNum() == id){
            TaskQuery.prepare(delete_sql_task);
            TaskQuery.addBindValue(task.getID());
            TaskQuery.exec();
            taskList.list.removeAt(i);
        }
        i++;
    }
    QListIterator<Project> pIterator(projectList.list);
    int j = 0;
    while(pIterator.hasNext()){
        project = pIterator.next();
        if(project.getProjectNum() == id){
            projectList.list.removeAt(j);
        }
        j++;
    }
}

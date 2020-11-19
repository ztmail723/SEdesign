#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include "entity.h"

class DatabaseActor{

public:
    static DatabaseActor& getInstance();

private:
    DatabaseActor();

    DatabaseActor(const DatabaseActor&) = delete;
    DatabaseActor(const DatabaseActor&&) = delete;
    DatabaseActor& operator=(const DatabaseActor&) = delete;
    ~DatabaseActor();

public:
    void connect();

    TaskList getTaskList();
    ProjectList getProjectList();
    UserList getUserList();
    MessageList getMessageList();

    void dataTakeOut();
    void setTaskList();
    void setProjectList();
    void setUserList();
    void setMessageList();

    void databaseUpdate();
    void updateTaskTable();
    void updateProjectTable();
    void updateMessageTable();
    void insertTaskTable();
    void insertProjectTable();
    void insertMessageTable();
    void insertAProject(Project);
    void deleteAProject(QString);

private:
    QSqlDatabase DB;

public:
    TaskList taskList, newTaskList;
    ProjectList projectList, newProjectList;
    UserList userList, newUserList;
    MessageList messageList, newMessageList;
};

#endif // DATABASE_H

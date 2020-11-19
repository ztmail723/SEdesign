#ifndef DATAPROJECT_H
#define DATAPROJECT_H
#include <datatask.h>
#include <QString>

class DataProject
{
public:
    DataProject();
    QString projectNum; //项目号
    DataTask tasks[3]; //项目里的任务
public:
    QString toString();
    DataProject(QString);
};

#endif // DATAPROJECT_H

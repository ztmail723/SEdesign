#include "dataproject.h"
/*
    QString projectNum; //项目号
    DataTask tasks[3]; //项目里的任务
*/

DataProject::DataProject()
{

}

QString DataProject::toString()
{
    return projectNum + "*" + tasks[0].toString() + "*" + tasks[1].toString() + "*" + tasks[2].toString();
}

DataProject::DataProject(QString str)
{
    auto args = str.split("*");
    this->projectNum = args[0];
    this->tasks[0] = DataTask(args[1]);
    this->tasks[1] = DataTask(args[2]);
    this->tasks[2] = DataTask(args[3]);
}

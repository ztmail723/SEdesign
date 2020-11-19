#include "datatask.h"

DataTask::DataTask()
{

}

QString DataTask::toString()
{
    QString s1 = projectNum;
    QString s2 = type;
    QString s3 = source;
    QString s4 = staffid;
    QString s5 = QString::number(hasRead);
    QString s6 = QString::number(hasFinished);
    return s1 + "$" + s2 + "$" + s3 + "$" + s4 + "$" + s5 + "$" + s6;
}

DataTask::DataTask(QString str)
{
    auto arg = str.split("$");
    projectNum = arg[0];
    type = arg[1];
    source = arg[2];
    staffid = arg[3];
    hasRead = arg[4].toInt();
    hasFinished = arg[5].toInt();
}

#ifndef TASKDATA_H
#define TASKDATA_H

#include <QObject>

class DataTask
{
public:
    DataTask();
    QString projectNum; //所属项目号
    QString type; //任务类型
    QString source; //任务来源
    QString staffid; //负责员工的id
    int hasRead; //已读标记
    int hasFinished; //完成标记
public:
    QString toString();
    DataTask(QString str);

};

#endif // TASKDATA_H

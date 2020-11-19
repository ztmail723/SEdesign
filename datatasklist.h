#ifndef TASKLISTDATA_H
#define TASKLISTDATA_H

#include <QObject>
#include <QList>
#include "datatask.h"
class DataTaskList
{
public:
    DataTaskList();
    QList<DataTask> myList;
public:
    QString toString();
    DataTaskList(QString str);
};

#endif // TASKLISTDATA_H

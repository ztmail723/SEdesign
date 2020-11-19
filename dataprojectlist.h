#ifndef DATAPROJECTLIST_H
#define DATAPROJECTLIST_H
#include <dataproject.h>
#include <QString>
#include <QList>

class DataProjectList
{
public:
    DataProjectList();
    QList<DataProject> pList;
public:
    QString toString();
    DataProjectList(QString);
};

#endif // DATAPROJECTLIST_H

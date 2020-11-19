#ifndef DATASTAFFLIST_H
#define DATASTAFFLIST_H
#include <QString>
#include <QList>
#include <datastaff.h>

class DataStaffList
{
public:
    DataStaffList();
    QList<DataStaff> slist;
public:
    QString toString();
    DataStaffList(QString);
};

#endif // DATASTAFFLIST_H

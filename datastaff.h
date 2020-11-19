#ifndef DATASTAFF_H
#define DATASTAFF_H
#include <QString>

class DataStaff
{
public:
    DataStaff();
    QString staffid; //员工id
    QString type; //员工类型
public:
    QString toString();
    DataStaff(QString);
};

#endif // DATASTAFF_H

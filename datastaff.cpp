#include "datastaff.h"
#include "QStringList"
/*
    QString staffid; //员工id
    QString type; //员工类型
*/
DataStaff::DataStaff()
{

}

QString DataStaff::toString()
{
    return this->staffid + "$" + this->type;
}

DataStaff::DataStaff(QString str)
{
    auto args = str.split("$");
    this->staffid = args[0];
    this->type = args[1];
}

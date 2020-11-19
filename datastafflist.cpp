#include "datastafflist.h"

DataStaffList::DataStaffList()
{

}

QString DataStaffList::toString()
{
    QString str = "";
    bool flag = true;
    for (auto i : this->slist)
    {
        if (flag)
        {
            flag = false;
        }
        else
        {
            str += "*";
        }
        str += i.toString();
    }
    return str;
}

DataStaffList::DataStaffList(QString str)
{
    auto args = str.split("*");
    for (auto i : args)
    {
        this->slist.append(DataStaff(i));
    }
}

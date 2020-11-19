#include "dataprojectlist.h"

DataProjectList::DataProjectList()
{

}

QString DataProjectList::toString()
{
    QString str = "";
    bool flag = true;
    for (auto i : this->pList)
    {
        if (flag)
        {
            flag = false;
        }
        else
        {
            str += "@";
        }
        str += i.toString();
    }
    return str;
}

DataProjectList::DataProjectList(QString str)
{
    auto args = str.split("@");
    for (auto i : args)
    {
        this->pList.append(DataProject(i));
    }
}

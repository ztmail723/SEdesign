#include "datatasklist.h"

DataTaskList::DataTaskList()
{

}

QString DataTaskList::toString()
{
    QString str = "";
    bool flag = true;
    for (DataTask& i : myList)
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

DataTaskList::DataTaskList(QString str)
{
    auto args = str.split("*");
    for (auto i = args.begin(); i != args.end(); i++)
    {
        this->myList.append(DataTask(*i));
    }
}

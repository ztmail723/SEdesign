#include "messagegenerator.h"

MessageGenerator::MessageGenerator()
{

}

QString MessageGenerator::t2001(int userIdentity, QString username, QString taskType)
{
    return QString::number(2001) + "#" + QString::number(userIdentity) + "#" + username + "#" + taskType;
}

QString MessageGenerator::t2002(DataTaskList& datatasklist)
{
    return QString::number(2002) + "#" + datatasklist.toString();
}

QString MessageGenerator::t2003(DataTaskList& datatasklist)
{
    return QString::number(2003) + "#" + datatasklist.toString();
}

QString MessageGenerator::t2004(DataStaffList& datastafflist)
{
    return QString::number(2004) + "#" + datastafflist.toString();
}

QString MessageGenerator::t2005(bool isSuccess, QString msg)
{
    QString sucTag;
    if (isSuccess)
    {
        sucTag = "1";
    }
    else
    {
        sucTag = "0";
    }
    return QString::number(2005) + "#" + sucTag + "#" + msg;
}

QString MessageGenerator::t2006(DataProjectList& dataprojectlist)
{
    return QString::number(2006) + "#" + dataprojectlist.toString();
}

QString MessageGenerator::t2007(DataStaffList& datastafflist)
{
    return QString::number(2007) + "#" + datastafflist.toString();
}

QString MessageGenerator::t2008(bool isSuccess, QString msg)
{
    QString sucTag;
    if (isSuccess)
    {
        sucTag = "1";
    }
    else
    {
        sucTag = "0";
    }
    return QString::number(2008) + "#" + sucTag + "#" + msg;
}

QString MessageGenerator::t2009(bool isSuccess, QString msg)
{
    QString sucTag;
    if (isSuccess)
    {
        sucTag = "1";
    }
    else
    {
        sucTag = "0";
    }
    return QString::number(2009) + "#" + sucTag + "#" + msg;
}

QString MessageGenerator::t2010(bool isSuccess, QString msg)
{
    QString sucTag;
    if (isSuccess)
    {
        sucTag = "1";
    }
    else
    {
        sucTag = "0";
    }
    return QString::number(2010) + "#" + sucTag + "#" + msg;
}

QString MessageGenerator::t2011(bool isSuccess, QString msg)
{
    QString sucTag;
    if (isSuccess)
    {
        sucTag = "1";
    }
    else
    {
        sucTag = "0";
    }
    return QString::number(2011) + "#" + sucTag + "#" + msg;
}

QString MessageGenerator::t3001(QString msg)
{
    return QString::number(3001) + "#" + msg;
}

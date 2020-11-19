#ifndef MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include <QObject>
#include "datatasklist.h"
#include "datastafflist.h"
#include "dataprojectlist.h"
class MessageGenerator : public QObject
{
    Q_OBJECT
public:
    explicit MessageGenerator();
    static QString t2001(int userIdentity, QString username, QString taskType);
    static QString t2002(DataTaskList& datatasklist);
    static QString t2003(DataTaskList& datatasklist);
    static QString t2004(DataStaffList& datastafflist);
    static QString t2005(bool isSuccess, QString msg);
    static QString t2006(DataProjectList& dataprojectlist);
    static QString t2007(DataStaffList& datastafflist);
    static QString t2008(bool isSuccess, QString msg);
    static QString t2009(bool isSuccess, QString msg);
    static QString t2010(bool isSuccess, QString msg);
    static QString t2011(bool isSuccess, QString msg);
    static QString t3001(QString msg);
    //QString t3002();
signals:

};

#endif // MESSAGEGENERATOR_H

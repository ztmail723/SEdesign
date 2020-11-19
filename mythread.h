#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(qintptr p);
    virtual void run();
public slots:
    void exit();
private:
    qintptr ptr;
};

#endif // MYTHREAD_H

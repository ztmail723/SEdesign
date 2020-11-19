QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    dataproject.cpp \
    dataprojectlist.cpp \
    datastaff.cpp \
    datastafflist.cpp \
    datatask.cpp \
    datatasklist.cpp \
    entity.cpp \
    main.cpp \
    mainwindow.cpp \
    messagegenerator.cpp \
    mytcpserver.cpp \
    mytcpsocket.cpp \
    mythread.cpp

HEADERS += \
    database.h \
    dataproject.h \
    dataprojectlist.h \
    datastaff.h \
    datastafflist.h \
    datatask.h \
    datatasklist.h \
    entity.h \
    mainwindow.h \
    messagegenerator.h \
    mytcpserver.h \
    mytcpsocket.h \
    mythread.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

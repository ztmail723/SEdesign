#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpserver.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyTcpServer* server = new MyTcpServer();
    server->setParent(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


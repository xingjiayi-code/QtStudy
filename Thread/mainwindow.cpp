#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,&MainWindow::sendNum,generate,&Generate::receNum);
    connect(generate,&Generate::gSendNumber,this,&MainWindow::gReceNum);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gReceNum(QVector<int> list)
{
   for(int i=0;i<list.size();i++){
       ui->listWidget->addItem(QString::number(list.at(i)));
   }
}


void MainWindow::on_pushButton_clicked()
{
   emit sendNum(100);
   generate->start();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_actionOpen_triggered()
{
   QString fileName = QFileDialog::getOpenFileName(this,"打开文件","D:\\qt\\test","*.txt");
   if(fileName.isEmpty()){
       QMessageBox::warning(this,"警告","请选择一个文件");
   }
   else{
       QFile * qFile = new QFile(fileName,this);
       qFile->open(QIODevice::ReadOnly);
       QByteArray qb =  qFile->readAll();
       ui->textEdit->setText(QString(qb));
       qFile->close();

   }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"保存文件","D:\\qt\\test");
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else{
        QFile * qFile = new QFile(fileName,this);
        qFile->open(QIODevice::WriteOnly);
       QByteArray qba ;
       qba.append(ui->textEdit->toPlainText());
       qFile->close();
    }
}

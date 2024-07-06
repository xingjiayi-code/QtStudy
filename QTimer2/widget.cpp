#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qTimer = new QTimer(this);
    connect(qTimer,&QTimer::timeout,[=](){
        QString path1 = "C:\\Users\\31845\\Pictures\\Saved Pictures\\";
        int static number = 1;
        QString path2 = ".jpg";
        QString path = path1+QString::number(number)+path2;
        qDebug() << "路径是" << path;
        QPixmap * pixMap = new QPixmap(path);
        ui->label->setPixmap(*pixMap);
        number++;
        if(number == 5){
            number == 1;
        }
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qTimer->start(TIMEOUT);
}

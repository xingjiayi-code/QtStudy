#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QTimer>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qtimer = new QTimer(this);
    connect(qtimer,&QTimer::timeout,[=](){
        QTime time = QTime ::currentTime();
        QString s = time.toString("hh:mm-ss.zzz");
        ui->label->setText(s);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked(bool checked)
{

    if(qtimer->isActive()){
        qtimer->stop();
        ui->pushButton->setText("开始");
    }
      else{
        qtimer->start(1000);
        ui->pushButton->setText("暂停");
    }
}

#include "widget.h"
#include "ui_widget.h"
#include <QSerialPortInfo>
#include <QStringList>
#include <QMessageBox>
#include <QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList listNamePort;
    serialPort = new QSerialPort(this);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(serialPortReadyRead_slot()));
    //QSerialPortInfo::availablePorts() 自动搜索当前可用的串口  QSerialPortInfo &info 元素是这个类型
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
       listNamePort<<info.portName();
    }
     ui->serialCb->addItems(listNamePort);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::serialPortReadyRead_slot(){

QString buffer;
buffer = QString(serialPort->readAll());
ui->recvEdit->appendPlainText(buffer);
}

void Widget::on_startBtn_clicked()
{
    QSerialPort::BaudRate baudRate; //波特率
    QSerialPort::DataBits dataBits; //数据位
    QSerialPort::StopBits stopBits; //校验位
    QSerialPort:: Parity  parity;   //停止位
    if(ui->baudrateCb->currentText() == "4800"){
        baudRate = QSerialPort::Baud4800;
    }
    else if(ui->baudrateCb->currentText() == "9600"){
        baudRate = QSerialPort::Baud9600;
    }
    else if(ui->baudrateCb->currentText() == "115200"){
        baudRate = QSerialPort::Baud115200;
    }
    //
    if(ui->dataCb->currentText() == "5"){
        dataBits = QSerialPort::Data5;
    }
    else if(ui->dataCb->currentText() == "6"){
       dataBits = QSerialPort::Data6;
    }
    else if(ui->dataCb->currentText() == "7"){
        dataBits = QSerialPort::Data7;
    }
    else if(ui->dataCb->currentText() == "8"){
        dataBits = QSerialPort::Data8;
    }
    //
    if(ui->stopCb->currentText() == "1"){
        stopBits = QSerialPort::OneStop;
    }
    else if(ui->baudrateCb->currentText() == "1.5"){
        stopBits = QSerialPort::OneAndHalfStop;
    }
    else if(ui->baudrateCb->currentText() == "2"){
        stopBits= QSerialPort::TwoStop;
    }
    //
    if(ui->checkCb->currentText() == "none"){
        parity = QSerialPort::NoParity;
    }
    //
    serialPort->setPortName(ui->serialCb->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(parity);
     if(serialPort->open(QIODevice::ReadWrite)){
         QMessageBox::information(this,"提示","成功");
     }
     else
     {
         QMessageBox::critical(this,"错误","失败");
     }
}

void Widget::on_stopBtn_clicked()
{
    serialPort->close();
}

void Widget::on_sendBtn_clicked()
{
    serialPort->write(ui->sendEdit->text().toLocal8Bit().data());
}

void Widget::on_clearBtn_clicked()
{
    ui->recvEdit->clear();
}

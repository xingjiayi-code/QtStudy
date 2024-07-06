#ifndef WIDGET_H
#define WIDGET_H
#include <QSerialPort>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();
    void serialPortReadyRead_slot();

    void on_sendBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::Widget *ui;
    QSerialPort * serialPort;

};
#endif // WIDGET_H

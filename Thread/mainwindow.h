#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <generate.h>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void gReceNum(QVector<int> list);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Generate * generate;
    int num;
signals:
    void sendNum(int num);
};
#endif // MAINWINDOW_H

#ifndef GENERATE_H
#define GENERATE_H

#include <QObject>
#include <QThread>
#include<QVector>

class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    void receNum(int num);
signals:
    void gSendNumber(QVector<int> list );
protected: void run() override;
private:
    int gNum;
    QVector<int> list;


};

#endif // GENERATE_H

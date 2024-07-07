#include "generate.h"
#include <QVector>
Generate::Generate(QObject *parent) : QThread(parent)
{

}

void Generate::receNum(int num)
{
    gNum = num;
}

void Generate::run()
{

    //生成随机数
    for(int i = 0;i < gNum ;i++){
        list.push_back(qrand() % 100);
    }
    emit gSendNumber(list);

}

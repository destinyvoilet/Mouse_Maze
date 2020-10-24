#ifndef START_H
#define START_H

#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <QSound>
#include <QMovie>
#include <QLabel>

#include "bigmap.h"
#include <config.h>
#include "modchoose.h"

class Start : public QWidget
{
    Q_OBJECT

public:
    Start(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);//绘图事件
    void timerEvent(QTimerEvent *event);
    int size = 35;
    //QTimer myTimer;


    ~Start();
public slots:
    void changemap();//点开切换界面，开始游戏
    //void ShutDown();
private:
    QPushButton Button1;
    QPushButton Button2;

    QLabel *Start_Label;
    QMovie *Start_Movie;
    QSound *S_Sound;
    BigMap World;
    modchoose modchoose1;

    int time_s;
};

#endif // START_H

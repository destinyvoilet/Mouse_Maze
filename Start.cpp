#include "start.h"
#include "bigmap.h"
/*#include <QDebug>
#include <QKeyEvent>
#include <QTimerEvent>*/
#include <modchoose.h>

static double Timer = 0;

Start::Start(QWidget *parent)
    : QWidget(parent)
{


    Button1.setParent(this);
    Button1.move(517,23);
    Button1.resize(741,541);
    Button1.setFlat(true);
    Button1.setStyleSheet("QPushButton{"
                   "border:2px outset green;"
                   "border-image:url(://res/开始按键_无底.png);"
                   "}"
                          );


    /*Button2.setParent(this);
    Button2.move(980,650);
    Button2.resize(240,120);
    Button2.setFlat(true);
    Button2.setStyleSheet("QPushButton{"
                   "border:2px outset green;"
                   "border-image:url(://res/退出游戏1.png);"
                   "}"
                          );*/


    srand(time(NULL));

    connect(&Button1,&QPushButton::released,this,&Start::changemap);
    connect(&Button2,&QPushButton::released,this,&Start::close);

    time_s = this->startTimer(100);


    Start_Label = new QLabel(this);
    Start_Movie = new QMovie(START_GIF);
    Start_Label->resize(STARTX,STARTY);
    Start_Label->move(0,0);
    S_Sound = new QSound(START_WAV);

    Start_Label->setMovie(Start_Movie);
    Start_Movie->start();
    S_Sound->play();


    Start_Label->setScaledContents(true);

    setWindowTitle("鼠道难");

    resize(STARTX,STARTY);
}

Start::~Start()
{
    delete Start_Label;
    delete Start_Movie;
    delete S_Sound;
}
void Start::changemap()
{       
    this->close();
    modchoose1.show();
    modchoose1.exec();
}
/*void Start::ShutDown()
{
    S_Sound->stop();
    Start_Label->close();
}*/

void Start::paintEvent(QPaintEvent *event){
    QPixmap pix(MAP_PATH);
    QPainter painter(this);
    painter.drawPixmap(0,0,STARTX,STARTY,pix);
    QFont font(this->font());
    font.setPointSize(size);
    painter.setFont(font);
}

void Start::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == this->time_s)
    {
        Timer++;
        if(Timer>25)
        {
            Start_Label->hide();
        }
    }

}

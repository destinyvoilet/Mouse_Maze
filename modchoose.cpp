#include "modchoose.h"
#include "ui_modchoose.h"
#include "config.h"

int time_start=0;
int time_go=0;
modchoose::modchoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modchoose)
{
    ui->setupUi(this);
    ui->pushButton_8->hide();
    ui->comboBox->hide();

    connect(ui->pushButton,&QPushButton::released,this,&modchoose::btshow);
    connect(ui->pushButton_2,&QPushButton::released,this,&modchoose::btshow);
    connect(ui->pushButton_3,&QPushButton::released,this,&modchoose::btshow);
    connect(ui->pushButton_4,&QPushButton::released,this,&modchoose::btshow);
    ui->backbt->hide();
    ui->backbt_2->hide();
    ui->pushButton_8->move(517,23);
    ui->pushButton_8->resize(741,541);
    ui->pushButton_8->setStyleSheet("QPushButton{"
                                    "border:2px outset green;"
                                    "border-image:url(://res/开始按键_无底.png);"
                                    "}"
                                    );

    resize(1280,800);
    setWindowTitle("鼠道难");

    go_Label = new QLabel(this);
    go_Movie = new QMovie("://res/选择进入1.gif");
    go_Label->resize(STARTX,STARTY);
    go_Label->move(0,0);
    go_Sound = new QSound("://res/选择进入.wav");

    go_Label->setMovie(go_Movie);
    go_Label->hide();


    go_Label->setScaledContents(true);
    times=this->startTimer(100);
}

modchoose::~modchoose()
{
    delete ui;
}

void modchoose::backstart() {
    this->hide();
}
void modchoose::pushshow() {
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->comboBox->hide();
    ui->pushButton_8->hide();
}

void modchoose::on_pushButton_clicked()
{
    hardnum = 1;//简单

}


void modchoose::on_pushButton_2_clicked()
{
    hardnum = 2;//中等
}

void modchoose::on_pushButton_3_clicked()
{
    hardnum = 3;//困难
}

void modchoose::on_pushButton_4_clicked()
{
    hardnum = 4;//地狱
}


void modchoose::on_comboBox_activated(const QString &arg1)
{
    QString a = "1分钟";
    QString b = "2分钟";
    QString c = "3分钟";
    QString d = "<请选择时间>";
    if(arg1 == a){
        p8show();
        timelong = 1;
    }
    if(arg1 == b){
        p8show();
        timelong = 2;
    }
    if(arg1 == c){
        p8show();
        timelong = 3;
    }
    if(arg1 == d){
        p8hide();
    }
}
//timelong 时间长度

void modchoose::on_pushButton_8_clicked()
{
    //进入游戏
    go_Label->show();
    go_Sound->play();
    go_Movie->start();
    time_start=1;
}

void modchoose::on_pushButton_9_clicked()
{

}

void modchoose::btshow(){
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->comboBox->show();

}
void modchoose::p8show(){
    ui->pushButton_8->show();

}

void modchoose::p8hide(){
    ui->pushButton_8->hide();

}



void modchoose::paintEvent(QPaintEvent *event){
    QPixmap pix("://res/开始界面_已进入.jpg");
    QPainter painter(this);
    painter.drawPixmap(0,0,STARTX,STARTY,pix);
}

void modchoose::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == this->times&&time_start)
    {
        time_go++;
        if(time_go>39)
        {
            go_Label->hide();
            World.settime(timelong*60);
            World.setchoice(hardnum);
            World.ReStart();
            World.show();
            this->close();
            time_start=0;
        }
    }

}

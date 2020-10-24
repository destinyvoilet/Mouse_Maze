#include "bigmap.h"
#include <ctime>
#include <QDebug>

static int Map_control[MAX_SIZE][MAX_SIZE]={};
static COORD Map_cover[MAX_SIZE][MAX_SIZE]={};
//横竖各留出位置放置边界
int once=1;

BigMap::BigMap(QWidget *parent) : QWidget(parent)
{
    Time_game = this->startTimer(1000);

    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {
            Map_cover[i][j].Y=(i+3)*80+60;
            Map_cover[i][j].X=(j+6)*80+20;
        }
    }

    Label3 = new QLabel(this);
    Label3->setPixmap(QPixmap("://res/结束界面.png"));
    Label3->resize(MAPX,MAPY);
    Label3->move(0,0);
    Label3->setScaledContents(true);
    Label3->hide();

    Button1.setParent(Label3);
    Button1.move(200,550);
    Button1.resize(80,80);
    Button1.setFlat(true);

    Button1.setStyleSheet("QPushButton{"
                   "border:2px outset green;"
                   "border-image:url(://res/重新开始(1).png);"
                   "}"
                          );

    Button2.setParent(Label3);
    Button2.move(1000,550);
    Button2.resize(80,80);
    Button2.setFlat(true);

    Button2.setStyleSheet("QPushButton{"
                   "border:2px outset green;"
                   "border-image:url(://res/退出游戏(1).png);"
                   "}"
                          );

    connect(&Button1,&QPushButton::released,this,&BigMap::ReStart);
    connect(&Button2,&QPushButton::released,this,&BigMap::close);

    myBlood.setParent(this);
    myBlood.move(0,10);
    myBlood.resize(64,8);
    myBlood.setRange(0,myMouse.Blood);
    myBlood.setValue(myMouse.Blood);
    myBlood.setTextVisible(false);

    Label1 = new QLabel(Label3);
    Label1->setPixmap(QPixmap("://res/胜利图标.png"));
    Label1->resize(460,350);
    Label1->move(450,50);
    Label1->setScaledContents(true);
    Label1->hide();

    Label2 = new QLabel(Label3);
    Label2->setPixmap(QPixmap("://res/失败图标.png"));
    Label2->resize(460,300);
    Label2->move(480,100);
    Label2->setScaledContents(true);
    Label2->hide();

    win_Sound = new QSound("://res/成功 叮咚.wav");
    lose_Sound = new QSound("://res/游戏失败.wav");
    bg_music = new QSound(BG_MUSIC);

    power=0;
    Alive = 1;
    choice=4;
    Road_num=0;
    Wall_num=0;
    first=1;
    blood_max=100;
    Map_size=20;
    Only_One=1;


    resize(MAPX,MAPY);
    setWindowTitle("鼠道难");

    myTimer.setInterval(GAMERATE_2);
    srand(time(NULL));
    Button1.hide();
    Button2.hide();
}

void BigMap::ReStart()//重置函数
{

    Alive=1;
    first=1;
    once=1;
    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {
            Map_cover[i][j].Y=(i+3)*80+60;
            Map_cover[i][j].X=(j+6)*80+20;
        }
    }
    myblock.clear();
    myblock.shrink_to_fit();
    x_num = 1;
    y_num = 1;
    myBlood.show();
    Button1.hide();
    Button2.hide();
    Label1->hide();
    Label2->hide();
    myBlood.setRange(0,blood_max);
    myMouse.Blood=blood_max;
    myBlood.setValue(myMouse.Blood);

    myBlood.move(myMouse.m_X-10,myMouse.m_Y-20);
    bg_music->play();
    bg_music->setLoops(QSound::Infinite);
    Road_num=0;
    Wall_num=0;
    generate_map();
    map();
    Label3->hide();
    if(Only_One)
    {
        playGame();
    }
    Only_One=0;
}

void BigMap::playGame()//游戏主体
{

    myTimer.start();
    connect(&myTimer,&QTimer::timeout,[=]()
    {
        Map_move(power);
        int Move=MouseMove();
        switch (Move) {
        case 0:
            break;
        case 1:
            myMouse.direction=5-myMouse.direction;
            power=1;
            Road_num=0;
            Wall_num=0;
            Map_move(power);
            Road_num=0;
            Wall_num=0;
            power=0;
            myMouse.direction=5-myMouse.direction;
            break;
        case 2:
            Alive=2;
            break;
        default:
            break;
        }
        myBlood.move(myMouse.m_X,myMouse.m_Y-20);
        myBlood.setValue(myMouse.Blood);
        if(Alive == 0)
        {
            bg_music->stop();
            myBlood.hide();
            if(once)
            {
                lose_Sound->play();
            }
            once=0;
            Label3->show();
            Button1.show();
            Button2.show();
            Label2->show();
        }

        if(Alive == 2)
        {
            myBlood.hide();
            bg_music->stop();
            if(once)
            {
                win_Sound->play();
            }
            once=0;
            Label3->show();
            Label1->show();
            Button1.show();
            Button2.show();
        }
        update();
    });
}

void BigMap::paintEvent(QPaintEvent *event)//绘图事件，用于绘制各个元素
{

    QPainter painter(this);
    QFont font(this->font());
    font.setPointSize(size);
    painter.setFont(font);

    if(Alive==1||Alive==0||Alive==2)
    {

    GameOver.setPosition(0,0);
    painter.drawPixmap(GameOver.m_X,GameOver.m_Y,MAPX,
                           MAPY,GameOver.m_GameOver);


    for(int i=0;i<Road_num_max;i++)
    {
          painter.drawPixmap(myRoad[i].m_X,myRoad[i].m_Y,
                           ROAD_SIZE,ROAD_SIZE,myRoad[i].m_Road);
    }
    int a=QAQ;
    myBarn.setPosition(Map_cover[a][a].X,Map_cover[a][a].Y);
    painter.drawPixmap(myBarn.m_X,myBarn.m_Y,BARN_SIZE,
                   BARN_SIZE,myBarn.m_Barn);

    for(int i=0;i<Wall_num_max;i++)
    {
        painter.drawPixmap(myWall[i].m_X,myWall[i].m_Y,myWall[i].Wall_Size,
                           myWall[i].Wall_Size,myWall[i].m_Wall);
    }
    if(myMouse.direction==1||myMouse.direction==4)
    {
        painter.drawPixmap(myMouse.m_X,myMouse.m_Y,35,
                           45,myMouse.m_Mouse);
        myMouse.m_Rect.setWidth(MOUSE_X);
        myMouse.m_Rect.setHeight(MOUSE_Y);
    }
    else if(myMouse.direction==2||myMouse.direction==3)
    {
        painter.drawPixmap(myMouse.m_X,myMouse.m_Y,45,
                           35,myMouse.m_Mouse);
        myMouse.m_Rect.setWidth(MOUSE_Y);
        myMouse.m_Rect.setHeight(MOUSE_X);
    }

    Road_num=0;
    Wall_num=0;
    }
    else if(Alive == 0)
    {
        Label3->show();
        Road_num=0;
        Wall_num=0;
    }
    else if(Alive == 2)
    {
        Road_num=0;
        Wall_num=0;
    }


}

void BigMap::keyPressEvent(QKeyEvent *event)//按键移动
{
    if(event->key()==Qt::Key_D)
    {
        myMouse.m_Mouse.load(MOUSE_PATH_1);
        power=1;
        myMouse.direction=3;
    }
    if(event->key()==Qt::Key_A)
    {
        myMouse.m_Mouse.load(MOUSE_PATH_2);
        power=1;
        myMouse.direction=2;
    }
    if(event->key()==Qt::Key_W)
    {
        myMouse.m_Mouse.load(MOUSE_PATH_3);
        power=1;
        myMouse.direction=1;
    }
    if(event->key()==Qt::Key_S)
    {
        myMouse.m_Mouse.load(MOUSE_PATH_4);
        power=1;
        myMouse.direction=4;
    }
}
void BigMap::keyReleaseEvent(QKeyEvent *event)//松键停止移动
{
    if(event->key()==Qt::Key_D)
    {
        power=0;
    }
    if(event->key()==Qt::Key_A)
    {
        power=0;
    }
    if(event->key()==Qt::Key_W)
    {
        power=0;
    }
    if(event->key()==Qt::Key_S)
    {
        power=0;
    }
}
void BigMap::timerEvent(QTimerEvent *event)//计时，主要是控制死亡动画和结束动画
{
    if(event->timerId() == this->Time_game&&Alive == 1)
    {
        myMouse.Blood--;
        if(myMouse.Blood<=0)
        {
            Alive=0;
        }
    }
}

int BigMap::MouseMove()
{

    for(int i=0;i<Wall_num;i++)
    {
        if(myMouse.m_Rect.intersects(myWall[i].m_Rect))
        {
            return 1;
        }
    }

    for(int i=0;i<Road_num;i++)
    {
        if(myMouse.m_Rect.intersects(myRoad[i].m_Rect))
        {
            return 0;
        }
    }
    if(myMouse.m_Rect.intersects(myBarn.m_Rect))
    {

        return 2;
    }
    return 0;
}
void BigMap::Map_move(bool p)
{
    if(p==1)
    {
        switch (myMouse.direction) {
        case 1://上
            for(int i=0;i<MAX_SIZE;i++)
            {
                for(int j=0;j<MAX_SIZE;j++)
                {
                    Map_cover[i][j].Y+=VELOCITY;
                }
            }
            break;
        case 2://左
            for(int i=0;i<MAX_SIZE;i++)
            {
                for(int j=0;j<MAX_SIZE;j++)
                {
                    Map_cover[i][j].X+=VELOCITY;
                }
            }
            break;
        case 3://右
            for(int i=0;i<MAX_SIZE;i++)
            {
                for(int j=0;j<MAX_SIZE;j++)
                {
                    Map_cover[i][j].X-=VELOCITY;
                }
            }
            break;
        case 4://下
            for(int i=0;i<MAX_SIZE;i++)
            {
                for(int j=0;j<MAX_SIZE;j++)
                {
                    Map_cover[i][j].Y-=VELOCITY;
                }
            }
            break;
        default:
            break;
        }
    }
    else {
        return;
    }
    map();
}

void BigMap::map()//地图
{
    for(int i=0;i<pow(2,choice-1)*10+1+2;i++)
    {
        for(int j=0;j<pow(2,choice-1)*10+1+2;j++)
        {
            if(Map_control[i][j]==ROAD)
            {
                    myRoad[Road_num].setPosition(Map_cover[i][j].X,
                            Map_cover[i][j].Y);
                    Road_num++;
            }
            else if(Map_control[i][j]==WALL)
            {
                myWall[Wall_num].setPosition(Map_cover[i][j].X,
                        Map_cover[i][j].Y);
                Wall_num++;
            }
        }
    }
    if(first)
    {
        Road_num_max=Road_num;
        Wall_num_max=Wall_num;
    }
    first=0;
}

void BigMap::settime(double t)
{
    blood_max=t;
}

void BigMap::setchoice(int ch)
{
    choice=ch;
}

BigMap::~BigMap()
{
    delete bg_music;
    delete Label1;
    delete Label2;
    delete Label3;
}

void BigMap::FindBlock(int m,int n)
{
    //找出与当前位置相邻的墙

    if (x_num + 1 <= m && Map_control[x_num + 1][y_num] == WALL) {//down
        myblock.push_back(block(x_num + 1, y_num, down));
    }
    if (y_num + 1 <= n && Map_control[x_num][y_num + 1] == WALL) {//RIGHT
        myblock.push_back(block(x_num, y_num + 1, RIGHT));
    }
    if (x_num - 1 >= 1 && Map_control[x_num - 1][y_num] == WALL) {//up
        myblock.push_back(block(x_num - 1, y_num, up));
    }
    if (y_num - 1 >= 1 && Map_control[x_num][y_num - 1] == WALL) {//LEFT
        myblock.push_back(block(x_num, y_num - 1, LEFT));
    }
}
void BigMap::generate_map()
{
    //将地图全部置为墙
    memset(Map_control, WALL, sizeof(Map_control));
    //定义起始点
    Map_control[1][1] = ROAD;
    start.x = start.y = 1;

    //srand((unsigned)time(NULL));//随机数种子
    FindBlock(QAQ,QAQ);
    //第一步压入两堵墙（起点右边和起点下面）进入循环
    while (myblock.size()) {
        int BlockSize = myblock.size();
        //随机选择一堵墙（生成0 ~ BlockSize-1之间的随机数，同时也是vector里墙的下标）
        int randnum = rand() % BlockSize;
        block SelectBlock = myblock[randnum];
        x_num = SelectBlock.row;//矿工来到我们“选择的墙”这里
        y_num = SelectBlock.column;
        //根据当前选择的墙的方向进行后续操作
        //此时，起始点 选择的墙 目标块 三块区域在同一直线上
        //我们让矿工从“选择的墙”继续前进到“目标块”
        //矿工有穿墙能力 ：)
        switch (SelectBlock.direction) {
        case down: {
            x_num++;
            break;
        }
        case RIGHT: {
            y_num++;
            break;
        }
        case LEFT: {
            y_num--;
            break;
        }
        case up: {
            x_num--;
            break;
        }
        }
        //目标块如果是墙
        if (Map_control[x_num][y_num] == WALL) {
            //打通墙和目标块
            Map_control[SelectBlock.row][SelectBlock.column] = Map_control[x_num][y_num] = ROAD;
            //再次找出与矿工当前位置相邻的墙
            FindBlock(QAQ,QAQ);
        }
        else {//如果不是呢？说明我们的矿工挖到了一个空旷的通路上面 休息一下就好了
            //relax
        }
        //删除这堵墙(把用不了的墙删了，对于那些已经施工过了不必再施工了，同时也是确保我们能跳出循环)
        myblock.erase(myblock.begin() + randnum);
    }
}

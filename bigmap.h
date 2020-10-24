#ifndef BIGMAP_H
#define BIGMAP_H

#include <QWidget>
#include <QTimer>
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QPoint>
#include <QString>
#include <QFont>
#include <QMovie>
#include <QLabel>
#include <QSound>
#include <mapix.h>
#include <vector>
#include <ctime>
#include <cmath>
#include <string.h>

#include "config.h"
#include "mouse.h"
#include "wall.h"
#include "road.h"
#include "barn.h"
#include "losegame.h"

#define down 1
#define RIGHT 2
#define LEFT 4
#define up 8
#define QAQ pow(2,choice-1)*10+1

class BigMap : public QWidget
{
    Q_OBJECT
public:
    explicit BigMap(QWidget *parent = nullptr);
    //void initmap();
    void playGame();
    //void updatePosition();
    void map();
    void settime(double);
    void setchoice(int);
    void generate_map();
    void FindBlock(int,int);
    Mouse myMouse;
    Barn myBarn;
    QSound *lose_Sound;
    QSound *win_Sound;

    Road myRoad[ROAD_NUM];
    Wall myWall[WALL_NUM];
    QProgressBar myBlood;
    int blood_max;

    LoseGame GameOver;

    QSound *bg_music;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);

    int Alive;
    bool Save;

    int MouseMove();
    void Map_move(bool);
    bool power;
    int choice;
    int Map_size;

    int size=50;

    int Wall_num;
    int Road_num;
    int Wall_num_max;
    int Road_num_max;

    int Score_Sum;
    int Only_One;

    int xp[MOUSE_INTERVAL];
    int yp[MOUSE_INTERVAL];
    bool first;

    QTimer myTimer;
    struct block {
        int row, column, direction;
        block(int _row, int _column, int _direction) {
            row = _row;
            column = _column;
            direction = _direction;
        }
    };

    struct point {
        int x;
        int y;
    }start, end;

    std::vector<block> myblock;
    int x_num = 1, y_num = 1;//矿工位置

    ~BigMap();

signals:

public slots:
    void ReStart();//重置函数
private:
    QPushButton Button1;
    QPushButton Button2;

    QLabel *Label1;
    QLabel *Label2;
    QLabel *Label3;

    int Time_game;
};
#endif // BIGMAP_H

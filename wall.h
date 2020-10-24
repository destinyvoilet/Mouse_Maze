#ifndef WALL_H
#define WALL_H

#include <QPixmap>
#include <config.h>


class Wall
{
public:
    Wall();
    void setPosition(int x,int y);
    QPixmap m_Wall;
    int m_X;
    int m_Y;
    int Wall_Size;
    QRect m_Rect;//矩形边框，检测碰撞
};

#endif // WALL_H

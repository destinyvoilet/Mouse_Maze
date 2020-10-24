#ifndef BARN_H
#define BARN_H
#include <QPixmap>
#include <config.h>

class Barn
{
public:
    Barn();
    void setPosition(int x,int y);
    QPixmap m_Barn;
    int m_X;
    int m_Y;
    int Barn_Size;
    QRect m_Rect;//矩形边框，检测碰撞
};

#endif // BARN_H

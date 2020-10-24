#ifndef MOUSE_H
#define MOUSE_H

#include <QPixmap>
#include <config.h>

class Mouse
{
public:
    Mouse();
    void setPosition(int x,int y);
    void move(bool power);

    QPixmap m_Mouse;
    int m_X;
    int m_Y;
    int Mouse_Size;
    QRect m_Rect;
    int direction;

    int Blood;
};

#endif // MOUSE_H

#ifndef ROAD_H
#define ROAD_H

#include <QPixmap>
#include <config.h>

class Road
{
public:
    Road();
    void setPosition(int x,int y);
    QPixmap m_Road;
    int m_X;
    int m_Y;
    int Road_Size;
    QRect m_Rect;

};

#endif // ROAD_H

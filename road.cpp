#include "road.h"

Road::Road()
{
    Road_Size = ROAD_SIZE;
    m_Road.load(ROAD_PATH);

    m_Rect.setWidth(Road_Size);
    m_Rect.setHeight(Road_Size);
    m_Rect.moveTo(m_X,m_Y);
}
void Road::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;

    m_Rect.moveTo(m_X,m_Y);
}

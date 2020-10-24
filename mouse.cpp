#include "mouse.h"

Mouse::Mouse()
{

    m_Mouse.load(MOUSE_PATH_1);
    m_X = 600;
    m_Y = 400;
    m_Rect.setWidth(MOUSE_Y);
    m_Rect.setHeight(MOUSE_X);
    m_Rect.moveTo(m_X,m_Y);
    direction=3;
}
void Mouse::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;

    m_Rect.moveTo(m_X,m_Y);
}

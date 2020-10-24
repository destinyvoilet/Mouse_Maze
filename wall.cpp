#include "wall.h"

Wall::Wall()
{
    Wall_Size = WALL_SIZE;
    m_Wall.load(WALL_PATH);

    m_Rect.setWidth(Wall_Size);
    m_Rect.setHeight(Wall_Size);
    m_Rect.moveTo(m_X,m_Y);

}
void Wall::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;

    m_Rect.moveTo(m_X,m_Y);
}


#include "barn.h"

Barn::Barn()
{
    Barn_Size = BARN_SIZE;
    m_Barn.load(BARN_PATH);

    m_Rect.setWidth(Barn_Size);
    m_Rect.setHeight(Barn_Size);
    m_Rect.moveTo(m_X,m_Y);

}
void Barn::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;

    m_Rect.moveTo(m_X,m_Y);
}

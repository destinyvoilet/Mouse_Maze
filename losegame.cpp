#include "losegame.h"

LoseGame::LoseGame()
{
    m_GameOver.load(LOST_PATH);

    m_Rect.setWidth(MAPX);
    m_Rect.setHeight(MAPY);
    m_Rect.moveTo(m_X,m_Y);

}
void LoseGame::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;

    m_Rect.moveTo(m_X,m_Y);
}

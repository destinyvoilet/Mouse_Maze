#ifndef LOSEGAME_H
#define LOSEGAME_H

#include <config.h>
#include <QPixmap>

class LoseGame
{
public:
    LoseGame();
    void setPosition(int x,int y);
    QPixmap m_GameOver;
    int m_X;
    int m_Y;
    QRect m_Rect;
};

#endif // LOSEGAME_H

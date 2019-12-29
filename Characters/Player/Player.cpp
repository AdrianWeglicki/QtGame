#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
Player::Player()
{
    setPixmap(QPixmap(":/Images/Images/spaceship.png").scaledToWidth(40));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()>50)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()< 700)
        {
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(pos().y() > 100)
        {
            setPos(x(),y()-10);
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y() < 500)
        {
            setPos(x(),y()+10);

        }
    }
}



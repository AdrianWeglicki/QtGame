#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player: public QGraphicsPixmapItem{
public:
    Player();   
    ~Player();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H

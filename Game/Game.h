#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Characters/Player/Player.h"
#include "Game/Spawn.h"
#include <QObject>

class Game: public QGraphicsView {

public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    Spawn * spawn;
};


#endif // GAME_H

#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Characters/Player/Player.h"
#include "Game/Spawn.h"
#include <QObject>
#include <QGroupBox>
#include <QPushButton>

class Game: public QGraphicsView {

public:
    Game(QWidget *parent=0);
    ~Game();
private:
    QGraphicsScene *scene;
    Player *player;
    Spawn *spawn;
    QPushButton *startButton;
    QPushButton *exitButton;

private slots:
    void handleStartButton();
    void handleExitButton();
    void mousePressEvent(QMouseEvent * e);
};


#endif // GAME_H

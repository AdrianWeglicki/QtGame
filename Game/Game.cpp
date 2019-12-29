#include "Game.h"
#include <QGraphicsView>
#include "Characters/Player/Player.h"
#include "Characters/Enemies/Enemy.h"
#include <QTimer>
#include <QGraphicsView>
Game::Game(QWidget *parent)
{
    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/background.png")));

    //create Player
    player = new Player();
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    spawn = new Spawn();
    scene->addItem(spawn);
    QTimer * timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),spawn,SLOT(startSpawnEnemy()));
    timerEnemy->start(1500);

    QTimer * timerMeteorEnemy = new QTimer();
    QObject::connect(timerMeteorEnemy,SIGNAL(timeout()),spawn,SLOT(startSpawnEnemyMeteor()));
    timerMeteorEnemy->start(2000);

}

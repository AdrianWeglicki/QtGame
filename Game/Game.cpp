#include "Game.h"
#include <QGraphicsView>
#include "Characters/Player/Player.h"
#include "Characters/Enemies/Enemy.h"
#include <QTimer>
#include <QGraphicsView>
#include <QRect>
#include <QApplication>
Game::Game(QWidget *parent)
{


    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    startButton = new QPushButton("Start", this);
    startButton->setGeometry(QRect(QPoint(300, 200),QSize(200, 50)));
    startButton->setStyleSheet("background-color: black; color:white; font-size: 20px");
    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(QRect(QPoint(300, 300),QSize(200, 50)));
    exitButton->setStyleSheet("background-color: black; color:white; font-size: 20px");

    connect(startButton, &QPushButton::clicked, this, &Game::handleStartButton);
    connect(exitButton, &QPushButton::clicked, this, &Game::handleExitButton);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/Images/Images/background.png")));


    setScene(scene);



}
void Game::handleExitButton(){

    QApplication::quit();
}

void Game::handleStartButton()
 {
     startButton->hide();
     exitButton->hide();

     //create Player
     player = new Player();
     player->setPos(400,500);
     player->setFlag(QGraphicsItem::ItemIsFocusable);

     // add the player to the scene
     scene->addItem(player);
     player->setFocus();

     //create Spawn
     spawn = new Spawn();
     scene->addItem(spawn);


     QTimer * timerEnemy = new QTimer();
     QObject::connect(timerEnemy,SIGNAL(timeout()),spawn,SLOT(startSpawnEnemy()));
     timerEnemy->start(1500);

     QTimer * timerMeteorEnemy = new QTimer();
     QObject::connect(timerMeteorEnemy,SIGNAL(timeout()),spawn,SLOT(startSpawnEnemyMeteor()));
     timerMeteorEnemy->start(2000);
 }
void Game::mousePressEvent(QMouseEvent * e)
{
   player->setFocus();
}
Game::~Game(){}

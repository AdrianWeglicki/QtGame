#include "Spawn.h"
#include "Characters/Enemies/Enemy.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

Spawn::Spawn(){

}

void Spawn::startSpawnEnemyMeteor()
{
    QPixmap *qpixmap = new QPixmap(":/Images/Images/meteor.png");
    Enemy * enemy = new Enemy(*qpixmap);
    scene()->addItem(enemy);

}

void Spawn::startSpawnEnemy()
{
    QPixmap *qpixmap = new QPixmap(":/Images/Images/enemy.png");
    Enemy * enemy = new Enemy(*qpixmap);
    scene()->addItem(enemy);
}


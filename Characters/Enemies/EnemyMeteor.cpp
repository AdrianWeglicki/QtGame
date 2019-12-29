#include "EnemyMeteor.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Characters/Player/Player.h"

EnemyMeteor::EnemyMeteor()
{
    int random_position = rand() % 700;
    setPos(random_position,-80);

    setPixmap(QPixmap(":/Images/Images/meteor.png").scaled(100,100));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
void EnemyMeteor::move(){

    //detection collisions
    QList<QGraphicsItem *> collidings_items =  collidingItems();
    for(int i=0, n=collidings_items.size(); i<n; ++i) {
        if(typeid( *(collidings_items[i])) == typeid(Player))
        {
                scene()->removeItem(collidings_items[i]);
                delete collidings_items[i];
                delete this;
                return;
        }
    }
    // move enemy down
    setPos(x(),y()+5);

     // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

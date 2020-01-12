#include "Enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDialog>
#include "Characters/Player/Player.h"
#include "Game/Game.h"
#include <QApplication>
#include <QMessageBox>


Enemy::Enemy(QPixmap &QPixmapImage)
{

    int random_position = rand() % 700;
    setPos(random_position,-80);

    setPixmap(QPixmapImage.scaled(100,100));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
void Enemy::move(){

    //detection collisions
    QList<QGraphicsItem *> collidings_items =  collidingItems();
    for(int i=0, n=collidings_items.size(); i<n; ++i) {
        if(typeid( *(collidings_items[i])) == typeid(Player))
        {
                scene()->removeItem(collidings_items[i]);
                delete collidings_items[i];

                //TODO: rozpoczecie gry od nowa. Rozwiązanie tymczasowe
                QMessageBox * message = new QMessageBox();
                message->setText("Przegrałeś! Zderzyłeś się z obiektem!");
                message->setWindowTitle("Przegrana");
                message->exec();

                QApplication::quit();
                /////////////////////
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
Enemy::~Enemy(){}

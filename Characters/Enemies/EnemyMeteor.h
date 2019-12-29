#ifndef ENEMYMETEOR_H
#define ENEMYMETEOR_H
#include <QObject>
#include <QGraphicsItem>

class EnemyMeteor: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    EnemyMeteor();

public slots:
        void move();
};
#endif // ENEMYMETEOR_H

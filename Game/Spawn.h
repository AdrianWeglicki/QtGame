#ifndef SPAWN_H
#define SPAWN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Spawn: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spawn();
    ~Spawn();
public slots:
    void startSpawnEnemyMeteor();
    void startSpawnEnemy();
};

#endif // SPAWN_H

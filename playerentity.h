#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <QTimer>
#include <QObject>

#include "livingentity.h"

class PlayerEntity: public QObject, public LivingEntity
{
    Q_OBJECT

private:
    QTimer *moveUTimer;
    QTimer *moveDTimer;
    QTimer *moveLTimer;
    QTimer *moveRTimer;
    QTimer *collisionTimer;

signals:
    void loadMapSignal(int id);

public slots:
    void moveUpSlot();
    void moveDownSlot();
    void moveLeftSlot();
    void moveRightSlot();
    void collisionSlot();

public:
    PlayerEntity(QString image, int x, int y, double speed, int maxHealth);
    void collision(int direction);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    int type() const override
    {
        return PLAYERENTITY;
    }
};

#endif // PLAYERENTITY_H

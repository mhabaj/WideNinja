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

    const int L = 1;
    const int R = 2;
    const int D = 3;
    const int U = 4;

signals:
    void loadMapSignal(int id);

public slots:
    void moveUpSlot();
    void moveDownSlot();
    void moveLeftSlot();
    void moveRightSlot();

public:
    PlayerEntity(double speed, int maxHealth);
    void collisions(int direction);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    int type() const override
    {
        return PLAYERENTITY;
    }
};

#endif // PLAYERENTITY_H

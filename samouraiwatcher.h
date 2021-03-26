#ifndef SAMOURAIWATCHER_H
#define SAMOURAIWATCHER_H

#include "livingentity.h"
#include <maincontroller.h>
#include <playerentity.h>
#include <QTimer>
#include <QList>
#include <QSequentialAnimationGroup>


class SamouraiWatcher : public QObject, public LivingEntity
{
    Q_OBJECT
    Q_PROPERTY(int time READ getTime WRITE setTime)

private :
    QTimer *changeDirectionTimer;
    QTimer *DetectionTimer;
    int status;
    MainController * mc;
    QSequentialAnimationGroup *group;
    QPixmap *upPix, *downPix, *leftPix, *rightPix;
    int time;

public slots :
    void up();
    void down();
    void left();
    void right();
    void detectionPlayerSlot();

public :
    SamouraiWatcher(int x, int y, int speed, int maxHealth, QString path, MainController *value);
    ~SamouraiWatcher();
    QTimer *getChangeDirectionTimer() const;
    int getStatus() const;
    MainController *getMc() const;

    int type() const override
    {
        return SAMOURAIWATCHER;
    }

    int getTime() const;
    void setTime(int value);
};

#endif // SAMOURAIWATCHER_H

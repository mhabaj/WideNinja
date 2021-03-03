#ifndef SAMOURAIWATCHER_H
#define SAMOURAIWATCHER_H

#include "livingentity.h"
#include <QTimer>
#include <maincontroller.h>
#include <QList>
#include <QListIterator>
#include <typeinfo>
#include <playerentity.h>


class SamouraiWatcher : public QObject, public LivingEntity
{
    Q_OBJECT

private :
    QTimer *changeDirectionTimer;
    QTimer *DetectionTimer;
    int status;
    MainController * mc;

public slots :
    void moveDirectionSlot();
    void detectionPlayerSlot();

public :
    SamouraiWatcher(QString image, int x, int y, int speed, int maxHealth, int watchTime, MainController *value);
    QTimer *getChangeDirectionTimer() const;
    int getStatus() const;
    MainController *getMc() const;


    int type() const override
    {
        return SAMOURAIWATCHER;
    }

};

#endif // SAMOURAIWATCHER_H

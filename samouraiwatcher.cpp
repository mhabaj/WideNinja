#include "samouraiwatcher.h"

SamouraiWatcher::SamouraiWatcher(QString image, int x, int y, int speed, int maxHealth ,int watchTime, MainController *value )
    : LivingEntity(image, x, y, speed, maxHealth)
{
    status = -1;
    mc = value;

    changeDirectionTimer = new QTimer();
    QObject::connect(changeDirectionTimer, SIGNAL(timeout()), this, SLOT(moveDirectionSlot()));

    DetectionTimer = new QTimer();
    QObject::connect(DetectionTimer, SIGNAL(timeout()), this, SLOT(detectionPlayerSlot()));

    changeDirectionTimer->start(watchTime *1000);
    DetectionTimer->start(10);
}


void SamouraiWatcher::moveDirectionSlot()
{
    if (status == -1)
    {
        setPixmap(* new QPixmap(":/Character/SamouraiDown"));
        status = 0;
    }
    else if (status == 0)
    {
        setPixmap(* new QPixmap(":/Character/SamouraiLeft"));
        status = 1;
    }
    else if (status == 1)
    {
        setPixmap(* new QPixmap(":/Character/SamouraiUp"));
        status = 2;
    }
    else if (status == 2)
    {
        setPixmap(* new QPixmap(":/Character/SamouraiRight"));
        status = -1;
    }  
}


void SamouraiWatcher::detectionPlayerSlot()
{
    int detectionWide = 65;
    int samouraiX = x();
    int samouraiY = y();

    int *coords = mc->getPlayerCoords();

    int playerX = coords[0];
    int playerY = coords[1];

    if (status == 0)
    {
        if(playerX > samouraiX - (detectionWide/2) && playerX < samouraiX + (detectionWide/2)
                &&  playerY > samouraiY && playerY <= 600)
        {
            qDebug() << "Je te vois ! Cours rouqin ! DOWN";
        }
    }
    else if (status == 1)
    {
        if(playerY > samouraiY - (detectionWide/2) && playerY < samouraiY + (detectionWide/2)
                &&  playerX < samouraiY && playerY >= 0)
        {
            qDebug() << "Je te vois ! Cours rouqin ! LEFT";
        }
    }
    else if (status == 2)
    {
        if(playerX > samouraiX - (detectionWide/2) && playerX < samouraiX + (detectionWide/2)
                &&  playerX < samouraiY && playerY >= 0)
        {
            qDebug() << "Je te vois ! Cours rouqin ! UP ";
        }
    }
    else if (status == -1)
    {
        if(playerY > samouraiY - (detectionWide/2) && playerY < samouraiY + (detectionWide/2)
                &&  playerX > samouraiX && playerX <= 600)
        {
            qDebug() << "Je te vois ! Cours rouqin ! RIGHT ";
        }
    }

}

MainController *SamouraiWatcher::getMc() const
{
    return mc;
}

int SamouraiWatcher::getStatus() const
{
    return status;
}

QTimer *SamouraiWatcher::getChangeDirectionTimer() const
{
    return changeDirectionTimer;
}

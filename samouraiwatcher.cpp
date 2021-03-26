#include "samouraiwatcher.h"

#include <QPropertyAnimation>

SamouraiWatcher::SamouraiWatcher(int x, int y, int speed, int maxHealth , QString path, MainController *value )
    : LivingEntity(x, y, speed, maxHealth)
{
    time = 0;
    status = -1;
    mc = value;

    upPix = new QPixmap(":/Character/SamouraiUp");
    downPix = new QPixmap(":/Character/SamouraiDown");
    leftPix = new QPixmap(":/Character/SamouraiLeft");
    rightPix = new QPixmap(":/Character/SamouraiRight");

    group = new QSequentialAnimationGroup();

    int firstDir = -1;

    QListIterator<QString> iterator(path.split(":"));

    while(iterator.hasNext()){
        QString direction = iterator.next();

        int duree = iterator.next().toInt();

        if(direction == "U"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "time");
            animation->setDuration(1000*duree);
            animation->setEndValue(0);
            if(group->animationCount() == 0){
                firstDir = U;
                setPixmap(*upPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(up()));
            group->addAnimation(animation);
        }
        else if(direction == "D"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "time");
            animation->setDuration(1000*duree);
            animation->setEndValue(0);
            if(group->animationCount() == 0){
                firstDir = D;
                setPixmap(*downPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(down()));
            group->addAnimation(animation);
        }
        else if(direction == "L"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "time");
            animation->setDuration(1000*duree);
            animation->setEndValue(0);
            if(group->animationCount() == 0){
                firstDir = L;
                setPixmap(*leftPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(left()));
            group->addAnimation(animation);
        }
        else if(direction == "R"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "time");
            animation->setDuration(1000*duree);
            animation->setEndValue(0);
            if(group->animationCount() == 0){
                firstDir = R;
                setPixmap(*rightPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(right()));
            group->addAnimation(animation);
        }
    }

    if(firstDir == U)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(up()));
    else if(firstDir == D)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(down()));
    else if(firstDir == L)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(left()));
    else if(firstDir == R)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(right()));

    group->setLoopCount(-1);
    group->start();

    DetectionTimer = new QTimer();
    QObject::connect(DetectionTimer, SIGNAL(timeout()), this, SLOT(detectionPlayerSlot()));

    DetectionTimer->start(10);
}

int SamouraiWatcher::getTime() const
{
    return time;
}

void SamouraiWatcher::setTime(int value)
{
    time = value;
}

void SamouraiWatcher::up()
{
    setPixmap(*upPix);
    status = 2;
}

void SamouraiWatcher::down()
{
    setPixmap(*downPix);
    status = 0;
}

void SamouraiWatcher::left()
{
    setPixmap(*leftPix);
    status = 1;
}

void SamouraiWatcher::right()
{
    setPixmap(*rightPix);
    status = -1;
}


void SamouraiWatcher::detectionPlayerSlot()
{
    int detectionWide = 96;
    bool obstacle = false;
    int samouraiX = x();
    int samouraiY = y();

    int** collisionMap = mc->getCollisionMap();
    int *coords = mc->getPlayerCoords();

    int playerX = coords[0]+16;
    int playerY = coords[1]+16;

    if (status == 0)
    {
        if(playerX > samouraiX - (detectionWide/2) && playerX < samouraiX + (detectionWide/2)
                &&  playerY > samouraiY && playerY <= 600)
        {
            for(int xCollision = (samouraiY/32) + 1; xCollision < playerY/32 ; xCollision++ )
            {

                if( collisionMap[playerX/32][xCollision] == 1)
                    obstacle = true ;
            }

            if( obstacle == false)
                qDebug() << "Je te vois ! Cours rouqin ! DOWN";
        }
    }
    else if (status == 1)
    {
        if(playerY > samouraiY - (detectionWide/2) && playerY < samouraiY + (detectionWide/2)
                &&  playerX < samouraiY && playerX > 0)
        {
            for(int yCollision = (samouraiX/32)-1 ; yCollision > playerX/32 ; yCollision-- )
            {
                if(collisionMap[yCollision][playerY/32] == 1)
                    obstacle = true ;
            }

            if( obstacle == false)
                qDebug() << "Je te vois ! Cours rouqin ! LEFT";
        }
    }
    else if (status == 2)
    {
        if(playerX > samouraiX - (detectionWide/2) && playerX < samouraiX + (detectionWide/2)
                &&  playerY < samouraiY && playerY >= 0)
        {
            for(int xCollision = (samouraiY/32) - 1; xCollision > playerY/32 ; xCollision-- )
            {

                if(collisionMap[playerX/32][xCollision] == 1)
                    obstacle = true ;
            }

            if( obstacle == false)
                qDebug() << "Je te vois ! Cours rouqin ! UP ";
            else
                qDebug() << "STEAKHACHE";
        }
    }
    else if (status == -1)
    {
        if(playerY > samouraiY - (detectionWide/2) && playerY < samouraiY + (detectionWide/2)
                &&  playerX > samouraiX +15 && playerX <= 600)
        {
            for(int yCollision = (samouraiX/32)+1 ; yCollision < playerX/32 ; yCollision++ )
            {
                if(collisionMap[yCollision][playerY/32] == 1)
                    obstacle = true ;
            }

            if( obstacle == false)
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

SamouraiWatcher::~SamouraiWatcher()
{
    delete upPix;
    delete downPix;
    delete leftPix;
    delete rightPix;

    group->stop();
    delete group;

    delete DetectionTimer;
}

#include "pathmonsterentity.h"

#include <QPropertyAnimation>

PathMonsterEntity::PathMonsterEntity(double speed, int maxHealth):
    LivingEntity(speed, maxHealth)
{
    group = new QSequentialAnimationGroup();
}

void PathMonsterEntity::setPath(QString path)
{
    int tempX = x();
    int tempY = y();

    QListIterator<QString> iterator(path.split(":"));

    while(iterator.hasNext()){
        int direction = iterator.next().toInt();

        int distance = iterator.next().toInt();

        if(direction == U){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration(800*distance);
            animation->setEndValue(tempY-distance*PIXELS);
            group->addAnimation(animation);
            tempY -= distance*PIXELS;
        }
        else if(direction == D){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration(800*distance);
            animation->setEndValue(tempY+distance*PIXELS);
            group->addAnimation(animation);
            tempY += distance*PIXELS;
        }
        else if(direction == L){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration(800*distance);
            animation->setEndValue(tempX-distance*PIXELS);
            group->addAnimation(animation);
            tempX -= distance*PIXELS;
        }
        else if(direction == R){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration(800*distance);
            animation->setEndValue(tempX+distance*PIXELS);
            group->addAnimation(animation);
            tempX += distance*PIXELS;
        }
    }

    group->setLoopCount(-1);
}

void PathMonsterEntity::start(){
    group->start();
}

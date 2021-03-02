#include "samouraiwatcher.h"


SamouraiWatcher::SamouraiWatcher(QString image, int x, int y, int speed, int maxHealth ,int watchTime,MainController *value )
    : LivingEntity(image, x, y, speed, maxHealth)
{
    status = -1;
    mc = value;

    changeDirectionTimer = new QTimer();
    QObject::connect(changeDirectionTimer, SIGNAL(timeout()), this, SLOT(moveDirection()));

    changeDirectionTimer->start(watchTime *1000);
}

void SamouraiWatcher::moveDirection()
{
    QList<QGraphicsItem *> listItems = mc->getScene()->items();

    for (int i = 0; i < listItems.length(); i++)
    {
        if(listItems[i]->type() == 66004)
        {
            qDebug() << "J'ai trouvé le joueur woooaaa";
            qDebug() << listItems[i]->x();
            qDebug() << listItems[i]->y();
        }
    }

    if (status == -1)
    {
        setPixmap(* new QPixmap(":/Character/NinjaDown"));
        status = 0;
        qDebug() << "Down";
    }
    else if (status == 0)
    {
        this->setPixmap(* new QPixmap(":/Character/NinjaLeft"));
        status = 1;
        qDebug() << "Left";
    }
    else if (status == 1)
    {
        this->setPixmap(* new QPixmap(":/Character/NinjaUp"));
        status = 2;
        qDebug() << "Up";
    }
    else if (this->status == 2)
    {
        this->setPixmap(* new QPixmap(":/Character/NinjaRight"));
        status = -1;
        qDebug() << "Right";
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

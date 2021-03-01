#include "playerinventory.h"
#include <QDebug>

int PlayerInventory::getCurrentLocation() const
{
    return currentLocation;
}

void PlayerInventory::setCurrentLocation(qint32 value)
{
    currentLocation = value;
}

PlayerInventory::PlayerInventory()
{
    inventory.insert("keyForest",0);
    inventory.insert("katana",0);
    inventory.insert("shuriken",0);
    
    tempInventory.insert("keyForest",0);
    tempInventory.insert("katana",0);
    tempInventory.insert("shuriken",0);
}

void PlayerInventory::addValue(QString key)
{
    inventory[key] += 1;
}

void PlayerInventory::substractValue(QString key)
{
    if(inventory[key] != 0)
    {
        inventory[key] -= 1;
    }
}

void PlayerInventory::addTempValue(QString key)
{
    tempInventory[key] += 1;
}

void PlayerInventory::substractTempValue(QString key)
{
    if(tempInventory[key] != 0)
    {
        tempInventory[key] -= 1;
    }
}

QMap<QString, int> PlayerInventory::getInventory() const
{
    return inventory;
}

void PlayerInventory::setInventory(const QMap<QString, qint32> &value)
{
    inventory = value;
}

QMap<QString, int> PlayerInventory::getTempInventory() const
{
    return tempInventory;
}

void PlayerInventory::setTempInventory(const QMap<QString, qint32> &value)
{
    tempInventory = value;
}

void PlayerInventory::pushTemp()
{
    QMapIterator<QString, qint32> i(tempInventory);

    while(i.hasNext()){
        i.next();
        inventory[i.key()] += i.value();
    }
}

void PlayerInventory::clearTemp()
{
    QMapIterator<QString, qint32> i(tempInventory);

    while(i.hasNext()){
        i.next();
        tempInventory[i.key()] = 0;
    }
}

void PlayerInventory::show()
{
    QMapIterator<QString, qint32> it(tempInventory);

    qDebug() << "Temp:";

    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << ": " << it.value();
    }

    QMapIterator<QString, qint32> i(inventory);

    qDebug() << "Normal:";

    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }


}


#include "playerinventory.h"
#include <QDebug>

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


void PlayerInventory::pushTemp()
{
    QMapIterator<QString, int> i(tempInventory);

    while(i.hasNext()){
        i.next();
        inventory[i.key()] += i.value();
    }
}

void PlayerInventory::clearTemp()
{
    QMapIterator<QString, int> i(tempInventory);

    while(i.hasNext()){
        i.next();
        tempInventory[i.key()] = 0;
    }
}

void PlayerInventory::show()
{
    QMapIterator<QString, int> it(tempInventory);

    qDebug() << "Temp:";

    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << ": " << it.value();
    }

    QMapIterator<QString, int> i(inventory);

    qDebug() << "Normal:";

    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }
}

int PlayerInventory::getValuePickable(QString item)
{
    return inventory[item] + tempInventory[item];

}


QMap<QString, int> PlayerInventory::getInventory() const
{
    return inventory;
}

void PlayerInventory::setInventory(const QMap<QString, int> &value)
{
    inventory = value;
}

QMap<QString, int> PlayerInventory::getTempInventory() const
{
    return tempInventory;
}

void PlayerInventory::setTempInventory(const QMap<QString, int> &value)
{
    tempInventory = value;
}

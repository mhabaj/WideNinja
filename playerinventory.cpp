#include "playerinventory.h"

PlayerInventory::PlayerInventory()
{
    map.insert("keyForest",0);
    map.insert("katana",0);
    map.insert("shuriken",0);
}

QMap<QString, int> PlayerInventory::getMap() const
{
    return map;
}

void PlayerInventory::setMap(const QMap<QString, int> &value)
{
    map = value;
}

void PlayerInventory::addValue(QString key)
{
    map[key] += 1;
}

void PlayerInventory::substractValue(QString key)
{
    if( map[key] != 0)
    {
        map[key] -= 1;
    }
}



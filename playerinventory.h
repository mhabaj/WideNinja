#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <QMap>

class PlayerInventory
{
private :
    QMap<QString, int> map;
public:
    PlayerInventory();
    QMap<QString, int> getMap() const;
    void setMap(const QMap<QString, int> &value);
    void addValue(QString key);
    void substractValue(QString key);
};

#endif // PLAYERINVENTORY_H

#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <QMap>

class PlayerInventory
{
private :
    QMap<QString, int> inventory;
    QMap<QString, int> tempInventory;
public:
    PlayerInventory();

    QMap<QString, int> getInventory() const;
    void setInventory(const QMap<QString, int> &value);
    void addValue(QString key);
    void substractValue(QString key);

    QMap<QString, int> getTempInventory() const;
    void setTempInventory(const QMap<QString, int> &value);
    void addTempValue(QString key);
    void substractTempValue(QString key);
    void pushTemp();
    void clearTemp();
    void show();
};

#endif // PLAYERINVENTORY_H

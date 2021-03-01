#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <QMap>
#include <QDataStream>
class PlayerInventory
{
private :
    QMap<QString, qint32> inventory;
    QMap<QString, qint32> tempInventory;
    qint32 currentLocation;
public:
    PlayerInventory();

    QMap<QString, int> getInventory() const;
    void setInventory(const QMap<QString, qint32> &value);
    void addValue(QString key);
    void substractValue(QString key);

    QMap<QString, int> getTempInventory() const;
    void setTempInventory(const QMap<QString, qint32> &value);
    void addTempValue(QString key);
    void substractTempValue(QString key);
    void pushTemp();
    void clearTemp();
    void show();
    int getCurrentLocation() const;
    void setCurrentLocation(int value);

};

#endif // PLAYERINVENTORY_H

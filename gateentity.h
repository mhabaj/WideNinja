#ifndef GATEENTITY_H
#define GATEENTITY_H

#include "warpentity.h"

class GateEntity : public WarpEntity
{

private :
    bool opened;
    QString key;
public:
    GateEntity(QString image, int x, int y, int id, int dx, int dy,QString key );

    int type() const override
    {
        return GATEENTITY;
    }
    bool getOpened() const;
    void setOpened(bool value);
    QString getKey() const;
    void setKey(const QString &value);
};

#endif // GATEENTITY_H

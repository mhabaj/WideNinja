#ifndef WARPENTITY_H
#define WARPENTITY_H

#include "entity.h"

class WarpEntity: public Entity
{
private:
    int id;
    int dx, dy;

public:
    WarpEntity(QString image, int x, int y, int id, int dx, int dy);

    int getId() const;
    void setId(int value);

    int type() const override
    {
        return WARPENTITY;
    }

    int getDx() const;
    void setDx(int value);
    int getDy() const;
    void setDy(int value);
};

#endif // WARPENTITY_H

#ifndef WARPENTITY_H
#define WARPENTITY_H

#include "entity.h"

class WarpEntity: public Entity
{
private:
    int id;

public:
    WarpEntity(QString image, int x, int y, int id);

    int getId() const;
    void setId(int value);

    int type() const override
    {
        return WARPENTITY;
    }
};

#endif // WARPENTITY_H

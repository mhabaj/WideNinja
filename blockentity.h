#ifndef BLOCKENTITY_H
#define BLOCKENTITY_H

#include "entity.h"

class BlockEntity: public Entity
{
public:
    BlockEntity(QString image, int x, int y);

    int type() const override
    {
        return BLOCKENTITY;
    }
};

#endif // BLOCKENTITY_H

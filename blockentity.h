#ifndef BLOCKENTITY_H
#define BLOCKENTITY_H

#include "entity.h"

class BlockEntity: public Entity
{
public:
    BlockEntity();

    int type() const override
    {
        return BLOCKENTITY;
    }
};

#endif // BLOCKENTITY_H

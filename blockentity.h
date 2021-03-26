#ifndef BLOCKENTITY_H
#define BLOCKENTITY_H

#include "entity.h"

class BlockEntity: public Entity
{
private:
    QPixmap *pix;
public:
    BlockEntity(QString image, int x, int y);
    ~BlockEntity();

    int type() const override
    {
        return BLOCKENTITY;
    }
};

#endif // BLOCKENTITY_H

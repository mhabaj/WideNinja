#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include "movableentity.h"

class LivingEntity: public MovableEntity
{
private:
    int maxHealth;
    int health;
public:
    LivingEntity(double speed, int maxHealth);
    int getMaxHealth() const;
    void setMaxHealth(int value);
    int getHealth() const;
    void setHealth(int value);

    int type() const override
    {
        return LIVINGENTITY;
    }
};

#endif // LIVINGENTITY_H

#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include "entity.h"

class LivingEntity: public Entity
{
private:
    int maxHealth;
    int health;
    int speed;
public:
    LivingEntity(int x, int y, double speed, int maxHealth);
    int getMaxHealth() const;
    void setMaxHealth(int value);
    int getHealth() const;
    void setHealth(int value);
    int getSpeed() const;
    void setSpeed(int value);

    int type() const override
    {
        return LIVINGENTITY;
    }
};

#endif // LIVINGENTITY_H

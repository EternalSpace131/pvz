#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H

#include "zombie.h"
#include "plants.h"

class FootballZombie:public Zombie
{
public:
    FootballZombie();
    void advance(int phase) override;
    void slowfree()override;
};

#endif // FOOTBALLZOMBIE_H

#ifndef CONEZOMBIE_H
#define CONEZOMBIE_H

#include "zombie.h"
#include "plants.h"

class ConeZombie:public Zombie
{
public:
    ConeZombie();
    void advance(int phase) override;
    void slowfree() override;
};

#endif // CONEZOMBIE_H

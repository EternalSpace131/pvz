#ifndef NORMALZOMBIE_H
#define NORMALZOMBIE_H

#include "zombie.h"
#include "plants.h"

class NormalZombie:public Zombie
{
public:
    NormalZombie();
    void advance(int phase) override;
    void slowfree() override;
};

#endif // NORMALZOMBIE_H

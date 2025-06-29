#ifndef SCREENZOMBIE_H
#define SCREENZOMBIE_H

#include "zombie.h"
#include "plants.h"


class ScreenZombie:public Zombie
{
public:
    ScreenZombie();
    void advance(int phase) override;
    void slowfree() override;
};

#endif // SCREENZOMBIE_H

#ifndef SUPERFOOTBALLZOMBIE_H
#define SUPERFOOTBALLZOMBIE_H

#include "plants.h"
#include "zombie.h"
#include <QGraphicsItem>
#include <QMovie>

class SuperFootballZombie:public Zombie
{
public:
    SuperFootballZombie();
    void advance(int phase) override;
    void slowfree()override;
};

#endif // SUPERFOOTBALLZOMBIE_H

#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H

#include "zombie.h"
#include "plants.h"
#include <QMovie>
#include <QObject>

class BucketheadZombie:public Zombie,public QObject
{
public:
    BucketheadZombie();
    void advance(int phase) override;
    void slowfree() override;
};

#endif // BUCKETHEADZOMBIE_H

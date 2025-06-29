#include "normalzombie.h"

NormalZombie::NormalZombie() {
    HP = 270;
    ATK = 4;
    state = WALK;
    speed = 0.7;
    is_slow = 0;
    slow_time = 120;
    if(rand() % 2){
        SetMovie(":/resources/NormalZombieWalk1.gif");
    }else{
        SetMovie(":/resources/NormalZombieWalk2.gif");
    }
};

void NormalZombie::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        if(state == ATTACK || state == WALK){
            state = DEAD;
            Sethead(":/resources/ZombieHead.gif");
            SetMovie(":/resources/ZombieDie.gif");
            movie->setSpeed(50);
        }else if(state == BURN){
            state = DEAD;
            speed = 0;
            SetMovie(":/resources/burn.gif");
        }
        if(state==DEAD && movie->frameCount() == movie->currentFrameNumber() + 1){
            delete this;
        }
        return;
    }

    //检测碰撞
    QList<QGraphicsItem*> item = collidingItems();
    if(!item.empty()){//有碰撞
        Plants *plant= qgraphicsitem_cast<Plants *>(item[0]);
        if(plant){
            plant->HP -= ATK;
            if(state != ATTACK){
                SetMovie(":/resources/NormalZombieAttack.gif");
                state=ATTACK;
            }
        }
        return;
    }else{
        if(state == ATTACK){
            state = WALK;
            if(rand() % 2){
                SetMovie(":/resources/NormalZombieWalk1.gif");
            }else{
                SetMovie(":/resources/NormalZombieWalk2.gif");
            }
        }
    }

    //减速处理
    if(is_slow){
        if(++count > slow_time){
            slowfree();
            return;
        }
        if(is_slow == 1){
            movie->setSpeed(50);
            speed=0.35;
        }
        if(is_slow == DEAD){
            movie->setSpeed(0);
            speed=0;
        }
    }

    //超出边界删除
    if(x() < 80) {
        lose();
        delete this;
        return;
    }
    setX(x() - speed);//实现移动
};

void NormalZombie::slowfree() {
    is_slow = 0;
    speed = 0.7;
    movie->setSpeed(100);
    return;
};


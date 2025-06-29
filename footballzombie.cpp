#include "footballzombie.h"

FootballZombie::FootballZombie() {
    HP = 1670;
    ATK = 4;
    state = WALK;
    speed = 1;
    is_slow = 0;
    slow_time = 110;
    SetMovie(":/resources/FootballZombieWalk.gif");
}

void FootballZombie::advance(int phase){
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
        if(state == DEAD && movie->frameCount() == movie->currentFrameNumber() + 1){
            delete this;
        }
        return;
    }

    //检测碰撞
    QList<QGraphicsItem*> item = collidingItems();
    if(!item.empty()){//有碰撞
        Plants *plant = qgraphicsitem_cast<Plants *>(item[0]);
        if(plant){
            plant->HP -= ATK;
            if(state != ATTACK){
                SetMovie(":/resources/FootballZombieAttack.gif");
                state=ATTACK;
            }
        }
        return;
    }else{
        if(state == ATTACK){
            state = WALK;
            SetMovie(":/resources/FootballZombieWalk.gif");
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
            speed = 0;
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

void FootballZombie::slowfree(){
    is_slow = 0;
    speed = 1;
    movie->setSpeed(100);
    return;
};

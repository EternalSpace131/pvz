#include "bucketheadzombie.h"

BucketheadZombie::BucketheadZombie() {
    HP = 1370;
    ATK = 4;
    state = WALK;
    speed = 0.7;
    is_slow = 0;
    slow_time = 120;
    SetMovie(":/resources/BucketZombieWalk.gif");
}

void BucketheadZombie::advance(int phase){
    if(!phase)return;
    update();
    if(HP <=270 && HP > 0 && state_change == 0){
        // qDebug() << HP;
        state_change = 1;
        if(state != ATTACK)SetMovie(":/resources/NormalZombieWalk1.gif");
        else SetMovie(":/resources/NormalZombieAttack.gif");
    }
    if(state == BURN) state_change = 1;
    if(HP <= 0 && state_change == 1){
        // qDebug() << HP;
        // qDebug() << "1e21e13d2";
        if(state == ATTACK || state == WALK){
            state = DEAD;
            Sethead(":/resources/ZombieHead.gif");
            SetMovie(":/resources/ZombieDie.gif");
            movie->setSpeed(50);
        }
        if(state == BURN){
            state = DEAD;
            speed = 0;
            // qDebug() << "BURN!!!";
            SetMovie(":/resources/burn.gif");
        }
        // qDebug() << state;
        if(state == DEAD && movie->frameCount() == movie->currentFrameNumber() + 1){
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
                if(!state_change)SetMovie(":/resources/BucketZombieAttack.gif");
                else SetMovie(":/resources/NormalZombieAttack.gif");
                state = ATTACK;
            }
        }
        return;
    }else{
        if(state == ATTACK){
            if(!state_change){
                SetMovie(":/resources/BucketZombieWalk.gif");
            }else {
                SetMovie(":/resources/NormalZombieWalk1.gif");
            }
            state = WALK;
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
            speed = 0.35;
        }
        if(is_slow == DEAD){
            movie->setSpeed(0);
            speed = 0;
        }
    }

    //超出边界删除
    if(x()< 80) {
        lose();
        delete this;
        return;
    }
    setX(x() - speed);//实现移动
};

void BucketheadZombie::slowfree() {
    is_slow = 0;
    speed = 0.7;
    movie->setSpeed(100);
    return;
};

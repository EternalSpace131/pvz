#include "superfootballzombie.h"

SuperFootballZombie::SuperFootballZombie() {
    HP = 2600;
    ATK = 10;
    state = WALK;
    is_slow = 0;
    speed = 1.5;
    slow_time = -1;
    is_super = true;
    SetMovie(":/resources/FootballZombieWalk.gif");
}

void SuperFootballZombie::advance(int phase){
    if(!phase)return;
    update();

    QImage image = movie->currentImage();
    for(int x = 0; x < image.width(); x++){
        for(int y = 0; y < image.height(); y++){
            QColor color = image.pixelColor(x, y);
            color = QColor(255, 0, 0, 128);
            image.setPixelColor(x, y, color);
        }
    }

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
                state = ATTACK;
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

void SuperFootballZombie::slowfree(){
    is_slow = 0;
    speed = 1.5;
    movie->setSpeed(100);
    return;
};

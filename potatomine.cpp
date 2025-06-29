#include "potatomine.h"

PotatoMine::PotatoMine() {
    HP = 300;
    ATK = 1800;
    state = 1;
    potatoTimer = new QTimer();
    potatoTimer->setInterval(15000);
    potatoTimer->start();
    connect(potatoTimer,&QTimer::timeout,[=](){
        state = 2;
        setMovie(":/resources/PotatoMineLighting.gif");
        potatoTimer->stop();
    });
    setMovie(":/resources/PotatoMineHide.gif");
    movie->setSpeed(50);
}

PotatoMine::~PotatoMine() {
    potatoTimer->stop();
}

void PotatoMine::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        delete this;
        return;
    }
    if(state == 2){
        QList<QGraphicsItem*> item1 = collidingItems();
        if(!item1.isEmpty()){
            bool is_zombie;
            foreach(QGraphicsItem* item,item1){
                is_zombie = false;
                Zombie* zombie = qgraphicsitem_cast<Zombie*>(item);
                if(zombie){
                    is_zombie = true;
                    zombie->HP -= ATK;
                    if(zombie->HP <= 270)zombie->state_change = 1;
                }
            }
            if(is_zombie){
                state = 3;
                setMovie(":/resources/PotatoMineBooming.gif");
            }
        }
    }
    if(state == 3 && movie->currentFrameNumber() == movie->frameCount() - 1) {
        delete this;
    }
}

bool PotatoMine::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode)const{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qAbs(other->x() - x()) <= 30 && other->y() == y();
}

void PotatoMine::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        if(Button::shovel_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(798,40),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            Button::shovel_activate = false;
            button->state = 0;
            delete this;
        }else if(Button::strength_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(180,50),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            button->count = 0;
            button->state = 0;
            Button::strength_activate = false;

            potatoTimer->setInterval(0);
        }
    }
}

QRectF PotatoMine::boundingRect() const{
    return state == 3 ? QRectF(-60, -70, 120, 140) : Plants::boundingRect();
}

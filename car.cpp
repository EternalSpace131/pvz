#include "car.h"

Car::Car() {
    ATK = 10000;
    speed = 15.0;
    state = 0;
}

void Car::advance(int phase){
    if(!phase)return;
    update();
    if(state == 0){
        QList<QGraphicsItem*> item1 = collidingItems();
        if(!item1.isEmpty()){
            foreach(QGraphicsItem* item,item1){
                if(item->x() - x()<20) {
                    state = 2;
                }
            }
        }
    }else if(state == 2){
        setX(x() + speed);
        QList<QGraphicsItem*> item1 = collidingItems();
        if(!item1.isEmpty()){
            foreach(QGraphicsItem* item,item1){
                Zombie* zombie = qgraphicsitem_cast<Zombie*>(item);
                if(zombie && zombie->x() - x() <= 20){
                    zombie->HP -= ATK;
                    zombie->state_change = 1;
                }
            }
        }
    }
    if(x()>WIDTH - 160) delete this;
}

void Car::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-30, -30, 60, 60),QPixmap(":/resources/car.png"));
}

bool Car::collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && other->y() == y();
}

QRectF Car::boundingRect() const{
    return QRectF(-30, -30, 60, 60);
}

void Car::mousePressEvent(QGraphicsSceneMouseEvent* event){
    Q_UNUSED(event);
    return;
}

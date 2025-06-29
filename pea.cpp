#include "pea.h"

Pea::Pea(int slow){
    ATK = 30;
    speed = 7.0;
    is_slow = slow;
};

Pea::~Pea(){};

QRectF Pea::boundingRect() const{
    return QRectF(-12, -28, 24, 24);
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(!is_slow)painter->drawPixmap(boundingRect(),QPixmap(":/resources/pea.png"),QRectF());
    else painter->drawPixmap(boundingRect(),QPixmap(":/resources/peasnow.png"),QRectF());
}

void Pea::advance(int phase){
    if(!phase)return;
    update();
    QList<QGraphicsItem*> item = collidingItems();
    if(!item.empty()){
        Zombie* zombie = qgraphicsitem_cast<Zombie*>(item[0]);//第一个碰到的僵尸
        if(zombie){
            zombie->HP -= ATK;
            if(is_slow == 1)zombie->count = 0;
            else if(is_slow == 2) zombie->count = -100;
            if(!zombie->is_slow)zombie->is_slow = is_slow;
            delete this;
            return;
        }
    }
    setX(x() + speed);
    if(x() > WIDTH || x() < 0){
        delete this;
    }
};

bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode);
    if(qAbs(other->x() - x()) < 30 && other->type() == Zombie::Type && other->y() == y()) return true;
    return false;
};//碰撞检测


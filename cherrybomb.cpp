#include "cherrybomb.h"

CherryBomb::CherryBomb() {
    HP = 300;
    ATK = 1800;
    state = 1;//准备爆炸
    setMovie(":/resources/CherryBombBooming.gif");
    movie->setSpeed(50);
}


void CherryBomb::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        delete this;
    }else if(state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1){
        state = 2;
        setMovie(":/resources/boom.gif");
        QList<QGraphicsItem*> item1 = collidingItems();
        if(!item1.isEmpty()){
            foreach(QGraphicsItem* item,item1){
                Zombie* zombie = qgraphicsitem_cast<Zombie*>(item);
                // qDebug() << "CHERRYBOMB!!";
                zombie->HP -= ATK;
                // qDebug() << zombie->HP;
                if(zombie->HP <= 0)zombie->state = BURN;
                // qDebug() << zombie->state;
            }
        }
    }else if(state == 2 && movie->currentFrameNumber() == movie->frameCount() - 1){
        delete this;
    }
}

bool CherryBomb::collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qAbs(other->y() - y()) <= 100 && ((other->x() - x() >= 0 && other->x()-x() <= 110) || (other->x() - x() >= -1.5 * 110 && other->x() - x() <= 0));
}

void CherryBomb::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(Button::shovel_activate){
            QGraphicsItem* item=scene()->itemAt(QPoint(798,40),transform());
            Button* button=qgraphicsitem_cast<Button*>(item);
            Button::shovel_activate = false;
            button->state=0;
            delete this;
        }
    }
}

QRectF CherryBomb::boundingRect() const{
    return state==2 ? QRectF(-100, -100, 200, 200) : Plants::boundingRect();
}

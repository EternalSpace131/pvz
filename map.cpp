#include "map.h"

Map::Map(int k) {
    type = k;
    state = 1;
}

void Map::advance(int phase){
    if(type == 1){
        if(!phase) return;
        update();
        if(Card::card_act)setCursor(Qt::PointingHandCursor);
        else if(!Card::card_act || !state) setCursor(Qt::ArrowCursor);
    }
    else return;
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(type){
        QGraphicsItem* item1 = scene()->itemAt(QPoint(230,0),transform());
        SelectPlants *sp = qgraphicsitem_cast<SelectPlants*>(item1);
        int id = Card::card_id;
        int cost = Card::cost[Card::mapping[id]];
        if(event->button() == Qt::LeftButton && Card::card_act && sp->sun_val >= cost){
            if(sp->sun_val != sp->sun_val - cost)sp->sun_val -= cost;
            QGraphicsItem* item = scene()->itemAt(QPoint(Card::pos[Card::card_id]),transform());
            Card* card = qgraphicsitem_cast<Card*>(item);
            card->state = 0;
            card->count = 0;
            Card::card_act = false;
            QPointF pos = mapToScene(event->pos());
            int x = ((int(pos.x()) - 249) / (110 - 30) *(110 - 30) + 300);
            int y = ((int(pos.y()) - 81) / 100 * 100 + 130);
            if(scene()->itemAt(QPoint(x,y),transform())->type() == Plants::Type) return;
            Plants* plant = nullptr;
            if (id == 0) {
                plant = new SunFlower;
            } else if (id == 1) {
                plant = new PeaShooter;
            } else if (id == 2) {
                plant = new SnowPeaShooter;
            } else if (id == 3) {
                plant = new PotatoMine;
            } else if (id == 4) {
                plant = new WallNut;
            } else if (id == 5) {
                plant = new Repeater;
            } else if (id == 6) {
                plant = new CherryBomb;
            }
            // qDebug() << x << y << id;
            plant->setPos(x,y);
            plant->setZValue(2);
            scene()->addItem(plant);
        }
        else if(sp->sun_val < cost || event->button() == Qt::RightButton){
            state = 0;
            Card::card_act = false;
        }
    }
    else return;
}

QRectF Map::boundingRect() const{
    return type?QRectF(-369, -235, 738, 470):QRectF(0,0,WIDTH,HEIGHT);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}



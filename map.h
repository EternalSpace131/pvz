#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include "card.h"
#include "plants.h"
#include "selectplants.h"
#include <QGraphicsSceneMouseEvent>
#include "sunflower.h"
#include "peashooter.h"
#include "repeater.h"
#include "snowpeashooter.h"
#include "cherrybomb.h"
#include "potatomine.h"
#include "wallnut.h"

class Map:public QGraphicsItem
{
public:
    Map(int t);
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect() const override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
protected:
    int state;
    int type;
};

#endif // MAP_H

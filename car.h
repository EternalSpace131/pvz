#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include "zombie.h"
#include <QGraphicsSceneMouseEvent>
#include "button.h"

class Car:public QGraphicsItem
{
public:
    Car();
    void advance(int phase) override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
    bool collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect() const override;
private:
    int ATK;
    double speed;
    int state;
};

#endif // CAR_H

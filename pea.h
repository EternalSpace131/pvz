#ifndef PEA_H
#define PEA_H

#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>
#include "zombie.h"

class Pea : public QGraphicsItem
{
public:
    Pea(int slow);
    ~Pea();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;//碰撞检测
private:
    double speed;
    int ATK;
    int is_slow;
};

#endif // PEA_H

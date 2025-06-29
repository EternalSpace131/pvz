#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "plants.h"
#include "zombie.h"
#include "button.h"
#include <QGraphicsSceneMouseEvent>

class CherryBomb:public Plants
{
public:
    CherryBomb();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect()const override;
private:
    int state;
};

#endif // CHERRYBOMB_H

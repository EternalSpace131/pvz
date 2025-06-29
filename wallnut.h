#ifndef WALLNUT_H
#define WALLNUT_H

#include "plants.h"
#include "button.h"
#include <QGraphicsSceneMouseEvent>

class WallNut:public Plants
{
public:
    WallNut();
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // WALLNUT_H

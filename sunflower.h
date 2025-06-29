#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plants.h"
#include "sun.h"
#include "button.h"
#include <QTimer>
#include <QObject>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>

class SunFlower:public Plants,public QObject,public QRandomGenerator
{
public:
    SunFlower();
    ~SunFlower();
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QTimer* sunTimer;
};

#endif // SUNFLOWER_H

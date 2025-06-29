#ifndef REPEATER_H
#define REPEATER_H

#include "plants.h"
#include "zombie.h"
#include "pea.h"
#include "button.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Repeater:public Plants,public QObject
{
public:
    Repeater();
    ~Repeater();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    QTimer* peaTimer;
    QTimer* peaTimer1;
};

#endif // REPEATER_H

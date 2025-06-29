#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plants.h"
#include "zombie.h"
#include "pea.h"
#include "button.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class PeaShooter:public Plants,public QObject
{
public:
    PeaShooter();
    ~PeaShooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    QTimer* peaTimer;
};

#endif // PEASHOOTER_H

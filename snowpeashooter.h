#ifndef SNOWPEASHOOTER_H
#define SNOWPEASHOOTER_H

#include "plants.h"
#include "zombie.h"
#include "pea.h"
#include "button.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class SnowPeaShooter:public Plants,public QObject
{
public:
    SnowPeaShooter();
    ~SnowPeaShooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    QTimer* peaTimer;
};

#endif // SNOWPEASHOOTER_H

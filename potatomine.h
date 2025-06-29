#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plants.h"
#include "zombie.h"
#include "button.h"
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QObject>

class PotatoMine:public Plants,public QObject
{
public:
    PotatoMine();
    ~PotatoMine();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode)const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect()const override;
private:
    QTimer *potatoTimer;
    int state;
public slots:
    void Ready();
};

#endif // POTATOMINE_H

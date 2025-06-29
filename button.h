#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#define SHOVEL 1//铲子
#define STRENGTH 2 //植物技能

class Button:public QGraphicsItem
{
public:
    Button(int s);
    void advance(int phase) override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect() const override;
    static bool shovel_activate;
    static bool strength_activate;
    int count;
    int state;//0为冷却
protected:
    int freeze_time;
    int type;
};

#endif // BUTTON_H

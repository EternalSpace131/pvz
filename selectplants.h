#ifndef SELECTPLANTS_H
#define SELECTPLANTS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QWidget>
#include "sun.h"
#include "peashooter.h"
#include "snowpeashooter.h"
#include "sunflower.h"
#include "wallnut.h"
#include "cherrybomb.h"
#include "potatomine.h"
#include "repeater.h"

class SelectPlants: public QGraphicsItem
{
public:
    SelectPlants();
    int sun_val;//初始阳光
    QRectF boundingRect() const override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
    void advance(int phase) override;//状态更新
    //碰撞检测
    bool collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const override;

private:
    QImage image;
    int count;//计时器
    int sun_generate_time;//阳光生成间隔的时间
    int pre_sunval;//上一阳光值
};

#endif // SELECTPLANTS_H

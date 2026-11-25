#ifndef SUN_H
#define SUN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QSoundEffect>
#include <QMovie>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class Sun:public QGraphicsItem,public QGraphicsScene
{
public:
    Sun(int k);//向日葵生产的阳光
    Sun(double a,double b);//天上掉落阳光
    ~Sun() override;//析构
    void advance(int phase) override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    int val;
    double _x;
    double _y;
protected:
    QMovie* movie;
    QSoundEffect* sound;
    double speed;
    int disapper_time;
    int state;
    int count;
};

#endif // SUN_H

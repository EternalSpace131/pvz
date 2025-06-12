#ifndef PLANTS_H
#define PLANTS_H

#include "zombie.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QDebug>
#include <QSoundEffect>

#define WIDTH 1400
#define HEIGHT 602

class Plants:public QGraphicsItem
{
public:
    Plants();
    ~Plants();
    int HP;//血量
    QRectF boundingRect() const override;
    enum {Type = UserType + 1};
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    bool collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    int type() const override;
protected:
    QMovie* movie;
    int ATK;//攻击力
};

#endif // PLANTS_H

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QMovie>
#include <QSoundEffect>
#include <QPainter>
#include <QGraphicsScene>
#include "losescene.h"

//为各种参数标号
#define WALK 0
#define ATTACK 1
#define DEAD 2
#define BURN 3
#define SLOW 1
#define NO_SLOW 0
#define WIDTH 1400
#define HEIGHT 602

class Zombie:public QGraphicsItem
{
public:
    Zombie();
    ~Zombie();
    int HP;//血量
    int ATK;//攻击力
    int state;//状态（死亡，灰烬，减速）
    int state_change;//当前状态是否改变
    int is_slow;//是否被减速
    double speed;//速度
    int slow_time;//减速恢复时间
    int count;
    bool is_super;
    bool is_screen;
    void lose();
    enum {Type = UserType + 2 };
    QRectF boundingRect()const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    bool collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void SetMovie(const QString &path);
    void Sethead(const QString &path);
    virtual void slowfree() = 0;//解除减速效果
protected:
    QMovie* movie;
    QMovie* head;
};

#endif // ZOMBIE_H

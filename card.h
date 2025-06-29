#ifndef CARD_H
#define CARD_H

#include "plants.h"
#include "selectplants.h"
#include "button.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>

class Card:public QGraphicsItem
{
public:
    Card(const QString& name);
    void advance(int phase)override;
    void paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    const static QMap<QString,int> freeze;    // 冷却时间映射表（植物名称 冷却时间）
    const static QMap<QString,int> id;      // ID映射表（植物名称 ID）
    const static QMap<int,QPoint> pos;      // 位置映射表（ID 卡片位置）
    const static QMap<QString,int> cost;    // 成本映射表（植物名称 阳光消耗）
    const static QMap<int,QString> mapping; // 序号配对表（ID 植物名称）
    static bool card_act;  // 卡片激活状态
    static int card_id;         // 当前激活卡片的ID
    int state;                  // 卡片状态
    int count;                // 计时器
    QString name;               // 卡片对应的植物名称
};

#endif // CARD_H

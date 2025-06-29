#include "selectplants.h"

SelectPlants::SelectPlants() {
    sun_val = 1500;
    count = 0;
    sun_generate_time = 700;
    pre_sunval = sun_val;
};

QRectF SelectPlants::boundingRect() const {
    return QRectF(0,0,530,90);
};

void SelectPlants::paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);

    //加载植物槽
    painter->drawPixmap(QRect(0,0,528,95),QPixmap(":/resources/PlantsLine.png"));

    //绘制字体及阳光值
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 23, 600, 110), Qt::AlignCenter, QString::number(sun_val));

};

void SelectPlants::advance(int phase){
    if(!phase)return;
    update();

    //增加阳光
    if(++count >= sun_generate_time){
        count = 0;
        double x = rand() % 700 + 300;
        double y = rand() % (602-130) + 130;
        Sun* sun = new Sun(x,y);
        sun->setZValue(4);
        scene()->addItem(sun);
    }
    if(sun_val != pre_sunval){
        pre_sunval=sun_val;
    }
};//状态更新
//碰撞检测
bool SelectPlants::collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode)const{
    Q_UNUSED(mode);
    return other->type() == other->Type && other->x() == x() && other->y() == y();
};


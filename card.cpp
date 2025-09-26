#include "card.h"

const QMap<QString, int> Card::id = {{"sunflower", 0}, {"peashooter", 1}, {"snowpeashooter", 2}, {"potatomine", 3},
                                     {"wallnut", 4}, {"repeater", 5}, {"cherrybomb", 6}};
const QMap<int,QPoint> Card::pos={{0,QPoint(350,45)},{1,QPoint(411,45)},{2,QPoint(472,45)},{3,QPoint(533,45)},{4,QPoint(594,45)},
                                     {5,QPoint(655,45)},{6,QPoint(716,45)}};
const QMap<int,QString> Card::mapping = {{0,"sunflower"}, { 1,"peashooter"}, {2,"snowpeashooter"}, {3,"potatomine"},
                                          {4,"wallnut"}, {5,"repeater"}, {6,"cherrybomb"}};
const QMap<QString, int> Card::freeze = {{"sunflower",175 * 0}, {"peashooter",175 * 0}, {"cherrybomb",175 * 0}, {"wallnut", 175 * 0},
                                         {"snowpeashooter", 175 * 0}, {"potatomine", 175 * 0}, {"repeater", 175 * 0}};
 //const QMap<QString, int> Card::freeze = {{"sunflower",175}, {"peashooter",175}, {"cherrybomb",175 * 6}, {"wallnut", 175 * 4},
   //                                      {"snowpeashooter", 175}, {"potatomine", 175 * 4}, {"repeater", 175}};
const QMap<QString,int> Card::cost={{"sunflower",50}, {"peashooter",100}, {"cherrybomb",150}, {"wallnut", 50},
                                       {"snowpeashooter", 175}, {"potatomine", 25}, {"repeater", 200}};


int Card::card_id = -1;
bool Card::card_act = false;

Card::Card(const QString& name_) {
    name = name_;
    count = 0;
    state = 0;
}

void Card::advance(int phase){
    if(!phase)return;
    update();
    if(count < freeze[name]){
        count++;
        state = 0;
        setCursor(Qt::ArrowCursor);
    }
    else{
        state = 1;
        setCursor(Qt::PointingHandCursor);
    }
}

void Card::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140),QPixmap(":/resources/card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70),QPixmap(":/resources/" + name + ".png"));

    QFont font;
    font.setPointSizeF(18);
    painter->setFont(font);
    painter->drawText(QPoint(-30,62),QString::number(cost[name]));

    if(count < freeze[name]){
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - double(count) / freeze[name])));
    }
}

QRectF Card::boundingRect() const{
    return QRectF(-20, -70, 40, 120);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((Button::shovel_activate) && event->button() == Qt::LeftButton){
        Button::shovel_activate=false;
    }else if(state && !card_act && event->button() == Qt::LeftButton){
        card_act = true;
        Card::card_id = id[name];
    }else if(state && card_act && event->button() == Qt::LeftButton){
        card_act = false;
    }
}

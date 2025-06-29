#include "button.h"
#include <QCursor>

bool Button::shovel_activate = true;
bool Button::strength_activate = false;

Button::Button(int s) {
    count = 0;
    freeze_time = 1600;
    state = 0;
    type = s;
}

void Button::advance(int phase){
    if(!phase) return;
    update();
    if(state){
        setCursor(Qt::PointingHandCursor);
    }
    else{
        setCursor(Qt::ArrowCursor);
        if(++count > freeze_time) state = 1;
    }
    if(type == SHOVEL){
        setCursor(Qt::PointingHandCursor);
    }
}

void Button::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::green);
    QFont font("Calibri", 18, QFont::Bold, true);
    painter->setFont(font);
    if(type == SHOVEL){
        painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/resources/ShovelBank.png"));
        painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/resources/Shovel.png"));
        painter->setPen(Qt::transparent);
    }else if (type == STRENGTH){
        painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/resources/button.png"));
        painter->drawText(boundingRect(), Qt::AlignCenter, "强化");
        painter->setPen(Qt::transparent);
        if(count < freeze_time){
            QBrush brush(QColor(0, 0, 0, 200));
            painter->setBrush(brush);
            painter->drawRect(QRectF(-78, -19, 156, 36 * (1 - double(count) / freeze_time)));
        }
    }
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(type == SHOVEL){
        if(shovel_activate == false && event->button() == Qt::LeftButton){
            shovel_activate = true;
        }else if(shovel_activate == true && event->button() == Qt::LeftButton) {
            shovel_activate = false;
        }
    }
    if(state){
        if(type == STRENGTH){
            if(strength_activate == false && event->button() == Qt::LeftButton){
                strength_activate = true;
            }else if(strength_activate== true && event->button() == Qt::LeftButton){
                strength_activate = false;
            }
        }
    }
}

QRectF Button::boundingRect() const{
    if(type==SHOVEL) return QRectF(-42,-36,80,72);
    return QRectF(-80, -20, 160, 40);
}

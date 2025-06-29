#include "wallnut.h"

WallNut::WallNut() {
    HP = 4000;
    ATK = 0;
    setMovie(":/resources/WallNut1.gif");
}

void WallNut::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 2666 && HP > 1333){
        setMovie(":/resources/WallNut2.gif");
    }else if(HP <=1333 && HP > 0){
        setMovie(":/resources/WallNut3.gif");
    }else if(HP <= 0){
        delete this;
        return;
    }
}

void WallNut::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(Button::shovel_activate){
            QGraphicsItem* item=scene()->itemAt(QPoint(798,40),transform());
            Button* button=qgraphicsitem_cast<Button*>(item);
            Button::shovel_activate = false;
            button->state=0;
            delete this;
        }else if(Button::strength_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(180,50),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            button->count = 0;
            button->state = 0;
            Button::strength_activate = false;

            this->HP = 6000;
        }
    }
}

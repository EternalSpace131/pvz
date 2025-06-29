#include "sunflower.h"

SunFlower::SunFlower() {
    HP = 300;
    ATK = 0;

    sunTimer = new QTimer();
    sunTimer->setInterval(20000);
    sunTimer->start();
    connect(sunTimer, &QTimer::timeout,[=](){
        Sun* sun = new Sun(25);
        sun->setX(x());
        sun->setY(y() - 20);
        sun->setZValue(4);
        scene()->addItem(sun);
    });

    setMovie(":/resources/SunFlowerMove.gif");
}

SunFlower::~SunFlower(){
    sunTimer->stop();
};

void SunFlower::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        delete this;
        return;
    }
}

void SunFlower::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(Button::shovel_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(798,40),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            button->count = 0;
            button->state = 0;
            Button::shovel_activate = false;
            delete this;
        }else if(Button::strength_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(180,50),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            button->count = 0;
            button->state = 0;
            Button::strength_activate = false;

            QTimer *time = new QTimer;
            time->setInterval(200);
            time->start();
            connect(time,&QTimer::timeout,[=](){
                static int k = 10;
                --k;
                if(k < 0){
                    time->stop();
                    k = 10;
                }
                Sun* sun = new Sun(25);
                sun->setX(x());
                sun->setY(y() - 20);
                sun->setZValue(4);
                scene()->addItem(sun);
            });
        }
    }
}

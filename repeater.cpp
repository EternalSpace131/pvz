#include "repeater.h"

Repeater::Repeater() {
    HP = 300;
    ATK = 30;
    peaTimer = new QTimer();
    peaTimer->setInterval(1400);
    peaTimer1 = new QTimer(this);
    peaTimer1->setInterval(1500);
    peaTimer->start();
    peaTimer1->start();
    connect(peaTimer, &QTimer::timeout,[=](){
        QList<QGraphicsItem*> items=collidingItems();
        if(!items.isEmpty()){// 当前行有僵尸
            Pea* pea = new Pea(0);
            pea->setX( x() + 32 );
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    });
    connect(peaTimer1, &QTimer::timeout,[=](){
        QList<QGraphicsItem*> items=collidingItems();
        if(!items.isEmpty()){// 当前行有僵尸
            Pea* pea = new Pea(0);
            pea->setX( x() + 32 );
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    });
    setMovie(":/resources/RepeaterMove.gif");
    movie->setSpeed(50);
}

Repeater::~Repeater(){
    peaTimer->stop();
    peaTimer1->stop();
};

void Repeater::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        delete this;
    }
};

bool Repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    return other->y() == y() && other->type() == Zombie::Type && other->x() > x();
}

void Repeater::mousePressEvent(QGraphicsSceneMouseEvent *event){
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
            time->setInterval(100);
            time->start();
            connect(time,&QTimer::timeout,[=](){
                static int k = 40;
                --k;
                if(k < 0){
                    time->stop();
                    k = 40;
                }
                Pea* pea = new Pea(0);
                pea->setX( x() + 32 );
                pea->setY(y());
                scene()->addItem(pea);
            });
        }
    }
}

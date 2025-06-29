#include "snowpeashooter.h"

SnowPeaShooter::SnowPeaShooter() {
    HP = 300;
    ATK = 30;
    peaTimer = new QTimer();
    peaTimer->setInterval(1400);
    peaTimer->start();
    connect(peaTimer, &QTimer::timeout,[=](){
        QList<QGraphicsItem*> item = collidingItems();
        if(!item.isEmpty()){// 当前行有僵尸
            Pea* pea = new Pea(1);
            pea->setX( x() + 32 );
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    });
    setMovie(":/resources/SnowPeaShooterMove.gif");
    movie->setSpeed(50);
}

SnowPeaShooter::~SnowPeaShooter(){
    peaTimer->stop();
}

void SnowPeaShooter::advance(int phase){
    if(!phase)return;
    update();
    if(HP <= 0){
        delete this;
    }
};

bool SnowPeaShooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    return other->y() == y() && other->type() == Zombie::Type && other->x() > x();
}

void SnowPeaShooter::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(Button::shovel_activate){
            QGraphicsItem* item = scene()->itemAt(QPoint(798,40),transform());
            Button* button = qgraphicsitem_cast<Button*>(item);
            Button::shovel_activate = false;
            button->count = 0;
            button->state = 0;
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
                static int k = 20;
                --k;
                if(k < 0){
                    time->stop();
                    k = 20;
                }
                Pea* pea = new Pea(1);
                pea->setX( x() + 32 );
                pea->setY(y());
                scene()->addItem(pea);
            });
        }
    }
}

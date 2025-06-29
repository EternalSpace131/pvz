#include "sun.h"
#include "qmovie.h"
#include "selectplants.h"

Sun::Sun(int k) {//向日葵生成的阳光
    val = k;
    _x = 0;
    _y = 0;
    movie = new QMovie(":/resources/sun.gif");
    movie->start();
    speed = 1;
    state = 1;
    count = 0;
    disapper_time = 100;
    sound = new QSoundEffect;
    sound->setSource(QUrl::fromLocalFile(":/resources/Sun.wav"));
    sound->setVolume(0.3f);
}

Sun::Sun(double a,double b){//天上掉落的阳光
    _x = a;
    _y = b;
    state = 1;
    val = 25;
    movie= new QMovie(":/resources/sun.gif");
    movie->start();
    speed = 1;
    disapper_time = 200;
    this->setX(_x);
    this->setY(90);
    sound = new QSoundEffect;
    sound->setSource(QUrl::fromLocalFile(":/resources/Sun.wav"));
    sound->setLoopCount(1);
    sound->setVolume(0.3f);
}

Sun::~Sun(){
    if(movie)delete movie;
    movie = nullptr;
}

void Sun::paint(QPainter*painter,const QStyleOptionGraphicsItem* option,QWidget*widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-35,-35,70,70),image);
}

void Sun::advance(int phase){
    if(!phase) return ;
    QGraphicsItem::update();

    //从顶部到底部自然掉落
    if(state == 1 && y() != _y) setY(y() + speed);
    //点击后向阳光槽移动
    if(state == 2 || state == 3){
        double dx = qAbs(250 - _x);
        double dy = qAbs(80 - _y);
        if(x() > 250 || y() > 80){
            if(( dx / dy ) > 12){
                dy = qAbs(70 - _y);
                dx = qAbs(350 - _x);
                speed = ( dx / dy ) * 10;
                setX(x() - ( dx / dy ) * 10);
                setY(y()-10);
                state=3;
            }else{
                speed=( dx / dy ) * 50;
                setX(x() - ( dx / dy ) * 50);
                setY(y() - 50);
            }
            return;
        }
    }
    //到达阳光槽 增加阳光值并销毁阳光
    if(( state == 2 || state == 3) && (x() < 250 || y() < 80 )) {
        QList<QGraphicsItem*> item = scene()->items(QPointF(270,0));
        SelectPlants* sp = qgraphicsitem_cast<SelectPlants*>(item[0]);
        sp->sun_val += val;
        delete this;
        return;
    }
    if(++count >= disapper_time){
        count = 0;
        delete this;
        return;
    }
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        state = 2;
        _x = x();
        _y = y();
    }
}

QRectF Sun::boundingRect() const{
    return QRectF(-35,-35,70,70);
}

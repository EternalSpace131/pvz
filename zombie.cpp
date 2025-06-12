#include "zombie.h"
#include "plants.h"
#include <Qtimer>
#include <QApplication>

Zombie::Zombie() {
    movie = nullptr;
    head = nullptr;
    HP = 0;
    ATK = 0;
    is_slow = 0;
    state_change = 0;
    speed = 0.0;
    slow_time = 0;
    count = 0;
    is_super = false;
    is_screen = false;
}

Zombie::~Zombie(){
    delete movie;
    delete head;
    movie = nullptr;
    head = nullptr;
}

QRectF Zombie::boundingRect() const{
    return QRectF(-30,-100,100,140);
}

void Zombie::paint(QPainter* painter,const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image = movie->currentImage();

    //减速状态下的僵尸变为蓝色
    if(is_slow && !is_super && !is_screen){
        for(int x = 0; x < image.width(); x++){
            for(int y = 0; y < image.height(); y++){
                QColor color = image.pixelColor(x, y);
                double blendRatio = 0.6;
                int r = static_cast<int>(color.red() * (1 - blendRatio));
                int g = static_cast<int>(color.green() * (1 - blendRatio));
                int b = static_cast<int>(color.blue() * (1 - blendRatio) + 255 * blendRatio);
                int a = color.alpha();
                QColor newColor(r, g, b, a);
                image.setPixelColor(x, y, newColor);
            }
        }
    }

    if (is_super) {
        for (int x = 0; x < image.width(); x++) {
            for (int y = 0; y < image.height(); y++) {
                QColor color = image.pixelColor(x, y);
                double blendRatio = 0.6;
                int r = static_cast<int>(color.red() * (1 - blendRatio) + 255 * blendRatio);
                int g = static_cast<int>(color.green() * (1 - blendRatio));
                int b = static_cast<int>(color.blue() * (1 - blendRatio));
                int a = color.alpha();
                QColor newColor(r, g, b, a);
                image.setPixelColor(x, y, newColor);
            }
        }
    }

    //头部动画
    if(head){
        QImage head_image = head->currentImage();
        if(is_slow){
            for(int x = 0; x < head_image.width(); x++){
                for(int y = 0; y < head_image.height(); y++){
                    QColor color = head_image.pixelColor(x, y);
                    color = QColor(0, 0, 250, color.alpha());
                    head_image.setPixelColor(x, y, color);
                }
            }
        }
        painter->drawImage(QRectF(-70,-100,140,140),head_image);
    }
    painter->drawImage(QRectF(-70,-100,140,140),image);
};

bool Zombie::collidesWithItem(const QGraphicsItem* other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    if(qAbs(other->x()-x()) <= 30 && other->y() == y() && other->type() == Plants::Type){
        return true;
    }
    return false;
}

int Zombie::type() const{
    return Type;
}

void Zombie::SetMovie(const QString &path)
{
    if(movie) delete movie;
    movie = new QMovie(path);
    movie->start();
}

void Zombie::Sethead(const QString &path)
{
    if(head) delete head;
    head = new QMovie(path);
    head->start();
}

void Zombie::lose(){
    LoseScene *ls = new LoseScene();
    ls->show();
    QTimer *timer = new QTimer;
    timer->setInterval(3000);
    timer->start();
    QObject::connect(timer,&QTimer::timeout,[=](){
        QApplication::quit();
    });
};


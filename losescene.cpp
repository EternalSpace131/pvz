#include "losescene.h"
#include "beginscene.h"

LoseScene::LoseScene(QWidget *parent)
    : QWidget{parent}
{
    lose_scene = new QGraphicsScene(this);
    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle("植物大战僵尸");

    bgc = new QGraphicsPixmapItem;
    bgc->setZValue(0);
    bgc->setPixmap(QPixmap(":/resources/Lose0.png"));
    lose_scene->addItem(bgc);

    QGraphicsView *view = new QGraphicsView(lose_scene, this);
    view->setFixedSize(900,600);
    view->show();

    //设置返回按钮
    MyPushButton *backBtn = new MyPushButton(":/resources/back.png");
    backBtn->setGeometry(780,0,100,100);
    backBtn->setParent(this);
    connect(backBtn,&QPushButton::clicked,[=](){
        this->hide();
        BeginScene *beginscene = new BeginScene;
        beginscene->show();
    });

}

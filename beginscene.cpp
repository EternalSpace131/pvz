#include "beginscene.h"
#include "mainwindow.h"
#include "help.h"

BeginScene::BeginScene(QWidget *parent)
    : QWidget{parent}
{
    begin_scene = new QGraphicsScene(this);
    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle("植物大战僵尸");

    bgc = new QGraphicsPixmapItem;
    bgc->setZValue(0);
    bgc->setPixmap(QPixmap(":/resources/bgc.png"));
    begin_scene->addItem(bgc);

    QGraphicsView *view = new QGraphicsView(begin_scene, this);
    view->setFixedSize(1000,780);
    view->show();

    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/resources/start.png");
    startBtn->setParent(this);
    startBtn->setGeometry(390,300,100,100);

    //帮助按钮
    MyPushButton *helpBtn = new MyPushButton(":/resources/help.png");
    helpBtn->setParent(this);
    helpBtn->setGeometry(390,350,100,100);

    //退出按钮
    MyPushButton *exitBtn = new MyPushButton(":/resources/exit.png");
    exitBtn->setParent(this);
    exitBtn->setGeometry(390,400,100,100);

    connect(startBtn,&QPushButton::clicked,[=](){
        this->hide();
        ZombieNote *zombie_note = new ZombieNote;
        zombie_note->setFixedSize(520,320);
        zombie_note->show();
    });
    connect(helpBtn,&QPushButton::clicked,[=](){
        this->hide();
        Help *help = new Help;
        help->setFixedSize(900,600);
        help->show();
    });
    connect(exitBtn,&QPushButton::clicked,[=](){
        this->close();
    });
}

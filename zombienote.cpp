#include "zombienote.h"

ZombieNote::ZombieNote(QWidget *parent)
    : QWidget{parent}
{
    zombie_note_scene = new QGraphicsScene(this);
    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle("植物大战僵尸");

    QGraphicsView *view = new QGraphicsView(zombie_note_scene, this);
    view->setFixedSize(900,600);
    view->show();

    MyPushButton *zombie_note = new MyPushButton(":/resources/ZombieNoteHelp.png");
    zombie_note->setFixedSize(520,320);
    zombie_note->setParent(this);
    zombie_note->setGeometry(0,0,520,320);

    connect(zombie_note,&QPushButton::clicked,[=](){
        this->hide();
        MainWindow *mainscene = new MainWindow;
        mainscene->setFixedSize(900,600);
        mainscene->show();
    });
}

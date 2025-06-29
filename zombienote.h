#ifndef ZOMBIENOTE_H
#define ZOMBIENOTE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "mypushbutton.h"
#include "mainwindow.h"

class ZombieNote : public QWidget
{
    Q_OBJECT
public:
    explicit ZombieNote(QWidget *parent = nullptr);\
private:
    QGraphicsScene *zombie_note_scene;

signals:
};

#endif // ZOMBIENOTE_H

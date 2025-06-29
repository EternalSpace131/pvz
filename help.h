#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mypushbutton.h"
#include <QVBoxLayout>

class Help : public QWidget
{
    Q_OBJECT
public:
    Help(QWidget *parent = nullptr);
private:
    QGraphicsPixmapItem *bgc;
    QGraphicsScene *help_scene;

signals:
};

#endif // HELP_H

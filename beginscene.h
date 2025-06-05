#ifndef BEGINSCENE_H
#define BEGINSCENE_H

#include <QWidget>
#include <QPainter>
#include "mypushbutton.h"
#include "zombienote.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class BeginScene : public QWidget
{
    Q_OBJECT
public:
    BeginScene(QWidget *parent = nullptr);
private:
    QGraphicsPixmapItem *bgc;
    QGraphicsScene *begin_scene;
signals:
};

#endif // BEGINSCENE_H

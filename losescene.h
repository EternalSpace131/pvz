#ifndef LOSESCENE_H
#define LOSESCENE_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class LoseScene : public QWidget
{
    Q_OBJECT
public:
    LoseScene(QWidget *parent = nullptr);
private:
    QGraphicsPixmapItem *bgc;
    QGraphicsScene *lose_scene;
signals:
};

#endif // LOSESCENE_H

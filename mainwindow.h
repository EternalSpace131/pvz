#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSoundEffect>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "map.h"
#include "normalzombie.h"
#include "conezombie.h"
#include "bucketheadzombie.h"
#include "footballzombie.h"
#include "superfootballzombie.h"
#include "screenzombie.h"
#include "button.h"
#include "car.h"
#include "mypushbutton.h"
#include "selectplants.h"
#include <QPainter>
#include <QPushButton>
#include <QTime>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>

using namespace std;

#define ROW1 130         // 第一行Y坐标
#define GAP 100          // 行间距
#define WIDTH1 1020       // 游戏场景宽度
#define HEIGHT 602       // 游戏场景高度
#define ZOMBIE_START 1028 // 僵尸生成起始X坐标
#define PLANT_START 300  // 植物可种植区域起始X坐标

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addZombie();//添加僵尸
    void addNormalZombie();
    void addConeZombie();
    void addBucketheadZombie();
    void addScreenZombie();
    void addFootballZombie();
    void addSuperFootballZombie();
    void check();//碰撞检测
    void keyPressEvent(QKeyEvent *);//键盘事件(暂停)
private:
    Map* map_pause; // 暂停
    bool paused; // 暂停状态标志
    QGraphicsScene *scene; // 管理所有游戏元素
    QGraphicsView *view; // 显示场景内容
    QTimer* timer; // 定时器
    QTimer* ready_timer;
    QTimer* Normal_timer;
    QTimer* Cone_timer;
    QTimer* Bucket_timer;
    QTimer* Screen_timer;
    QTimer* Football_timer;
    QTimer* Super_timer;
    QTimer* Total_timer;
    QTimer* Re_timer;
    QGraphicsPixmapItem *bg; // 背景图片
    QGraphicsPixmapItem *bg_stop;
    QSoundEffect* sound_bg; // 背景音乐
};
#endif // MAINWINDOW_H

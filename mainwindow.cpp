#include "mainwindow.h"
#include "beginscene.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime()))); // 基于当前时间设置随机数种子

    timer = new QTimer; // 创建定时器来控制游戏循环
    scene = new QGraphicsScene(this); // 创建场景
    scene->setSceneRect(100, 0, WIDTH1, HEIGHT); // 设置场景可视区域
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // 禁用场景索引

    view = new QGraphicsView(scene,this);
    view->resize(WIDTH1 + 2,HEIGHT + 2);
    timer->start(33);
    view->show();

    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle("植物大战僵尸");

    bg_stop = new QGraphicsPixmapItem; // 创建暂停图片项
    bg_stop->setZValue(5); // 设置Z轴层级
    bg_stop->setPos(450,280);
    bg_stop->setPixmap(QPixmap(":/resources/stop.png")); // 加载暂停图片

    //设置背景音乐
    sound_bg = new QSoundEffect(this);
    sound_bg->setSource(QUrl::fromLocalFile(":/resources/crazyDave.wav"));
    sound_bg->setLoopCount(QSoundEffect::Infinite);
    sound_bg->setVolume(0.6f);
    sound_bg->play();

    bg = new QGraphicsPixmapItem; // 创建背景图片项
    bg->setZValue(0); // 设置Z轴层级
    bg->setPixmap(QPixmap(":/resources/Background.jpg")); // 加载背景图片
    scene->addItem(bg); // 将背景添加到场景

    SelectPlants* sp = new SelectPlants; // 创建植物槽界面
    sp->setPos(230, 0); // 设置植物槽位置
    sp->setZValue(3); // 层级高于背景，低于按钮
    scene->addItem(sp); // 添加植物槽到游戏场景

    Map* map = new Map(1); // 创建地图对象
    map->setZValue(2); // 层级高于背景，低于植物槽和按钮
    map->setPos(618, 326); // 设置地图位置
    scene->addItem(map); // 添加地图到游戏场景
    map_pause = new Map(0);//暂停

    //设置铲子按钮
    Button* button = new Button(SHOVEL);
    button->setPos(798,40);
    button->setZValue(3);
    scene->addItem(button);

    Button* strengthBtn = new Button(STRENGTH);
    strengthBtn->setPos(180,50);
    button->setZValue(5);
    scene->addItem(strengthBtn);

    //设置小推车
    for(int i = 0 ; i < 5 ; i ++){
        Car *car = new Car();
        car->setPos(PLANT_START - 80,ROW1 + i * GAP);
        car->setZValue(3);
        scene->addItem(car);
    }

    //设置植物槽
    for(int i = 0 ; i < 7 ;i ++){
        Card *card = new Card(Card::mapping[i]);
        card->setZValue(3);
        card->setPos( 350 + 61 * i, 45);
        scene->addItem(card);
    }

    connect(timer,&QTimer::timeout,scene,&QGraphicsScene::advance);//触发所有advance函数

    Cone_timer = new QTimer;
    Cone_timer->setInterval(7000);

    Bucket_timer = new QTimer;
    Bucket_timer->setInterval(7000);

    Screen_timer = new QTimer;
    Screen_timer->setInterval(7000);

    Football_timer = new QTimer;
    Football_timer->setInterval(7000);

    Normal_timer = new QTimer;
    Normal_timer->setInterval(10000);

    Total_timer = new QTimer;
    Total_timer->setInterval(5000);

    ready_timer = new QTimer;
    ready_timer->setInterval(30000);
    // ready_timer->setInterval(0);
    ready_timer->start();
    connect(ready_timer,&QTimer::timeout,[=](){
        Normal_timer->start();
        ready_timer->stop();
        // delete ready_timer;
    });

    connect(Normal_timer,&QTimer::timeout,[=](){
        static int num = 10;
        if(num--)addNormalZombie();
        if(num < 0){
            Cone_timer->start();
            Normal_timer->stop();
            // delete Normal_timer;
        }
    });

    connect(Cone_timer,&QTimer::timeout,[=](){
        static int num = 8;
        if(num--)addConeZombie();
        if(num < 0){
            Bucket_timer->start();
            Cone_timer->stop();
            // delete Cone_timer;
        }
    });

    connect(Bucket_timer,&QTimer::timeout,[=](){
        static int num = 8;
        if(num--)addBucketheadZombie();
        if(num < 0){
            Screen_timer->start();
            Bucket_timer->stop();
            // delete Bucket_timer;
        }
    });

    connect(Screen_timer,&QTimer::timeout,[=](){
        static int num = 6;
        if(num--)addScreenZombie();
        if(num < 0){
            Football_timer->start();
            Screen_timer->stop();
            // delete Screen_timer;
        }
    });

    connect(Football_timer,&QTimer::timeout,[=](){
        static int num = 6;
        if(num--)addFootballZombie();
        if(num < 0){
            static bool jud = false;
            if(jud == false){
                Total_timer->start();
                jud = true;
            }
            Football_timer->stop();
            // delete Football_timer;
        }
    });

    connect(Total_timer,&QTimer::timeout,[=](){
        addZombie();
    });

    Super_timer = new QTimer;
    Super_timer->setInterval(60000 * 1.5);
    Super_timer->start();
    connect(Super_timer,&QTimer::timeout,[=](){
        addSuperFootballZombie();
    });

    Re_timer = new QTimer;
    Re_timer->setInterval(360000);
    Re_timer->start();
    connect(Re_timer,&QTimer::timeout,[=](){
        Normal_timer->start();
    });

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

MainWindow::~MainWindow(){
    delete map_pause;
    delete scene;
    delete view;
    delete timer;
    delete sound_bg;
    map_pause = nullptr;
    scene = nullptr;
    view = nullptr;
    timer = nullptr;
    sound_bg = nullptr;
}

void MainWindow::addNormalZombie(){
    Zombie *zombie = new NormalZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addConeZombie(){
    Zombie *zombie = new ConeZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addBucketheadZombie(){
    Zombie *zombie = new BucketheadZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addScreenZombie(){
    Zombie *zombie = new ScreenZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addFootballZombie(){
    Zombie *zombie = new FootballZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addSuperFootballZombie(){
    Zombie* zombie = new SuperFootballZombie();
    int row = ( rand() % 5 ) * GAP + ROW1;
    zombie->setPos(ZOMBIE_START,row);
    zombie->setZValue(5);
    scene->addItem(zombie);
}

void MainWindow::addZombie(){
    // qDebug() << "开始生成僵尸";
    static int low = 4;
    static int high = 8;
    static int max_time = 20 * 1000 / 33;
    static int time = max_time / 2;
    static int count = 295;
    qDebug() << count << time;
    if(++count > time){
        if (++low > high){
            max_time /= 1.3;
            high *= 2;
        }
        int type = rand() % 100;
        Zombie* zombie = nullptr;
        if(type<10)
            zombie = new NormalZombie();
        else if(type<30)
            zombie = new ConeZombie();
        else if(type<50)
            zombie = new ScreenZombie();
        else if(type<75)
            zombie = new BucketheadZombie();
        else if(type<90)
            zombie = new FootballZombie();
        else
            zombie = new SuperFootballZombie();
        int row = ( rand() % 5 ) * GAP + ROW1;
        zombie->setPos(ZOMBIE_START,row);
        zombie->setZValue(5);
        scene->addItem(zombie);

        int type1 = rand() % 100;
        if(type<10)
            zombie = new NormalZombie();
        else if(type<30)
            zombie = new ConeZombie();
        else if(type<50)
            zombie = new ScreenZombie();
        else if(type<75)
            zombie = new BucketheadZombie();
        else if(type<100)
            zombie = new FootballZombie();
        int row1 = ( rand() % 5 ) * GAP + ROW1;
        zombie->setPos(ZOMBIE_START,row1);
        zombie->setZValue(5);
        scene->addItem(zombie);
        // qDebug() << "已添加僵尸";
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        // qDebug() << "空格";
        if (paused) {
            scene->removeItem(bg_stop);
            timer->start(); // 恢复计时器
            sound_bg->setVolume(0.6f);
            scene->removeItem(map_pause);
            paused = false;
        } else {
            scene->addItem(bg_stop); // 将背景添加到场景
            timer->stop();  // 暂停计时器
            sound_bg->setVolume(0.0f);
            map_pause->setZValue(10);
            map_pause->setPos(0,0);
            scene->addItem(map_pause);
            paused = true;
        }
    }

    // 调用父类的键盘事件处理函数
    QWidget::keyPressEvent(event);
}




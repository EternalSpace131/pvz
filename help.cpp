#include "help.h"
#include "beginscene.h"

Help::Help(QWidget *parent)
    : QWidget{parent}
{
    help_scene = new QGraphicsScene(this);
    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle("植物大战僵尸");

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(240, 240, 255));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    QGraphicsTextItem *textItem = new QGraphicsTextItem;
    QString htmlText =
        "<div style='width: 800px; margin: 20px auto; font-family: \"Microsoft YaHei\", sans-serif;'>"
        "<div style='background: linear-gradient(135deg, #2c3e50 0%, #3498db 100%); color: white; padding: 20px; border-radius: 10px 10px 0 0; box-shadow: 0 4px 6px rgba(0,0,0,0.1);'>"
        "<h1 style='text-align: center; margin: 0; text-shadow: 2px 2px 4px rgba(0,0,0,0.3);'>游戏帮助中心</h1>"
        "</div>"

        "<div style='background-color: #f8f9fa; padding: 20px; border-radius: 0 0 10px 10px; box-shadow: 0 4px 12px rgba(0,0,0,0.1);'>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #3498db; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>游戏规则</h2>"
        "<p style='color: #555; line-height: 1.6;'>经典游戏，无需多言（种植植物抵挡僵尸的入侵）</p>"
        "</div>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #27ae60; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>植物图鉴</h2>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌻 向日葵</h3>"
        "<p style='color: #666; line-height: 1.6;'>重要的能源植物，每隔一段时间会生产阳光</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 豌豆射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>可以攻击前方一整行的僵尸，每次发射一颗普通豌豆</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 土豆地雷</h3>"
        "<p style='color: #666; line-height: 1.6;'>种植时会潜伏在地底，一段时间后会出土，并对单格僵尸造成高额伤害。</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 双发射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>升级版豌豆射手，可攻击前方一整行的僵尸且每次射出两颗普通豌豆。</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 寒冰射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>可攻击前方一整行的僵尸，每次射出一颗冰豌豆，对僵尸造成减速效果。</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 樱桃炸弹</h3>"
        "<p style='color: #666; line-height: 1.6;'>对爆炸范围内的僵尸造成大杀伤力爆破伤害。</p>"
        "</div>"

        "<div class='plant-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #27ae60; font-size: 18px; margin-top: 0;'>🌱 坚果</h3>"
        "<p style='color: #666; line-height: 1.6;'>用结实的身体阻挡僵尸前进</p>"
        "</div>"
        "</div>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #e74c3c; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>僵尸图鉴</h2>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 普通僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>平平无奇的僵尸</p>"
        "</div>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 路障僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>由于头上有一顶帽子使得普通僵尸得到了大幅度增强</p>"
        "</div>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 铁桶僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>由于头上有更结实的铁桶使得普通僵尸得到了更大幅度的增强</p>"
        "</div>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 铁网门僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>它的铁网门是一个有效的护盾，并且可以抵挡冰豌豆的减速效果</p>"
        "</div>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 橄榄球僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>生命力与速度均是僵尸中的顶尖</p>"
        "</div>"

        "<div class='zombie-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #e74c3c; font-size: 18px; margin-top: 0;'>🧟 超级橄榄球僵尸</h3>"
        "<p style='color: #666; line-height: 1.6;'>僵尸博士的最新发明：狂暴药水！可以使得僵尸得到大幅度增强，但同时也有很强的副作用，只有强壮的橄榄球僵尸可以担此大任。<br>它拥有比普通橄榄球僵尸更高的血量，更快的速度，更大的攻击力，以及红温的外表，甚至强大到可以抵挡一次爆炸伤害而不死亡。</p>"
        "</div>"
        "</div>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #f39c12; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>植物强化技能</h2>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化向日葵</h3>"
        "<p style='color: #666; line-height: 1.6;'>在极短时间内迅速产出大量阳光</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化豌豆射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>向前方发射大量豌豆。</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化双发射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>向前方发射更大量的豌豆</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化寒冰射手</h3>"
        "<p style='color: #666; line-height: 1.6;'>向前方发射大量冰豌豆</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化坚果</h3>"
        "<p style='color: #666; line-height: 1.6;'>以更加结实的身体阻挡僵尸前进</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 强化土豆地雷</h3>"
        "<p style='color: #666; line-height: 1.6;'>瞬间出土，无需等待准备时间</p>"
        "</div>"

        "<div class='ability-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #f39c12; font-size: 18px; margin-top: 0;'>🌟 （强化）樱桃炸弹</h3>"
        "<p style='color: #666; line-height: 1.6;'>它还能强化吗？</p>"
        "</div>"
        "</div>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #9b59b6; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>操作指南</h2>"

        "<div class='tip-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #9b59b6; font-size: 18px; margin-top: 0;'>⌨️ 空格</h3>"
        "<p style='color: #666; line-height: 1.6;'>点击即可暂停/继续游戏</p>"
        "</div>"

        "<div class='tip-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #9b59b6; font-size: 18px; margin-top: 0;'>🔧 强化按钮</h3>"
        "<p style='color: #666; line-height: 1.6;'>点击强化按钮后，再点击你所要强化的植物，即可触发相应植物的技能（与2代中的能量豆机制类似）。注意：强化按钮有冷却时间</p>"
        "</div>"
        "</div>"

        "<div class='section' style='margin-bottom: 25px; border-left: 3px solid #34495e; padding-left: 15px;'>"
        "<h2 style='color: #2c3e50; font-size: 22px; margin-top: 0;'>注意事项</h2>"

        "<div class='warning-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #34495e; font-size: 18px; margin-top: 0;'>⚠️ 强化限制</h3>"
        "<p style='color: #666; line-height: 1.6;'>不要试图通过强化来叠加坚果的血量，这样做是徒劳的</p>"
        "</div>"

        "<div class='warning-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #34495e; font-size: 18px; margin-top: 0;'>⚠️ 游戏模式</h3>"
        "<p style='color: #666; line-height: 1.6;'>本游戏设计为无尽模式（也就是你无法胜利）</p>"
        "</div>"

        "<div class='warning-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #34495e; font-size: 18px; margin-top: 0;'>⚠️ 游戏失败机制</h3>"
        "<p style='color: #666; line-height: 1.6;'>在僵尸进入房子后会弹出失败画面，并在三秒后退出游戏，重新打开即可继续挑战</p>"
        "</div>"

        "<div class='warning-card' style='background-color: white; border-radius: 8px; margin-bottom: 15px; padding: 15px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); transition: transform 0.3s;'>"
        "<h3 style='color: #34495e; font-size: 18px; margin-top: 0;'>🔙 返回按钮</h3>"
        "<p style='color: #666; line-height: 1.6;'>返回键在右上角，点击可返回主菜单</p>"
        "</div>"
        "</div>"

        "<div class='thanks' style='background-color: #3498db; color: white; padding: 15px; border-radius: 8px; text-align: center; margin-top: 30px; box-shadow: 0 2px 5px rgba(0,0,0,0.2);'>"
        "<h3 style='margin: 0;'>在最后，非常感谢您的游玩！若有任何不满意的地方还请多多谅解，祝您游玩愉快！</h3>"
        "</div>"
        "</div>"
        "</div>";
    textItem->setHtml(htmlText);
    QFont font;
    font.setFamily("Microsoft YaHei"); // 设置字体类型，这里以微软雅黑为例
    font.setPointSize(14); // 设置字体大小
    font.setBold(true); // 设置字体为粗体
    font.setItalic(false); // 不设置为斜体
    font.setUnderline(false); // 不设置下划线
    textItem->setFont(font);

    help_scene->addItem(textItem);

    QGraphicsView *view = new QGraphicsView(help_scene, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    view->setFixedSize(900,500);
    layout->addWidget(view);
    setLayout(layout);

    MyPushButton *backBtn = new MyPushButton(":/resources/back.png");
    backBtn->setParent(this);
    backBtn->setGeometry(700,0,100,100);

    connect(backBtn,&QPushButton::clicked,[=](){
        this->close();
        BeginScene *bs = new BeginScene;
        bs->setFixedSize(1000,780);
        bs->show();
    });
}

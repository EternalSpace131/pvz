#include "mainwindow.h"
#include "beginscene.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeginScene w;

    w.setFixedSize(900,600);
    w.setWindowIcon(QIcon(":/resources/logo.png"));
    w.setWindowTitle("植物大战僵尸");
    w.show();
    return a.exec();
}

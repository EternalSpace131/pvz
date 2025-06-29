QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beginscene.cpp \
    bucketheadzombie.cpp \
    button.cpp \
    car.cpp \
    card.cpp \
    cherrybomb.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    help.cpp \
    losescene.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mypushbutton.cpp \
    normalzombie.cpp \
    pea.cpp \
    peashooter.cpp \
    plants.cpp \
    potatomine.cpp \
    repeater.cpp \
    screenzombie.cpp \
    selectplants.cpp \
    snowpeashooter.cpp \
    sun.cpp \
    sunflower.cpp \
    superfootballzombie.cpp \
    wallnut.cpp \
    zombie.cpp \
    zombienote.cpp

HEADERS += \
    beginscene.h \
    bucketheadzombie.h \
    button.h \
    car.h \
    card.h \
    cherrybomb.h \
    conezombie.h \
    footballzombie.h \
    help.h \
    losescene.h \
    mainwindow.h \
    map.h \
    mypushbutton.h \
    normalzombie.h \
    pea.h \
    peashooter.h \
    plants.h \
    potatomine.h \
    repeater.h \
    screenzombie.h \
    selectplants.h \
    snowpeashooter.h \
    sun.h \
    sunflower.h \
    superfootballzombie.h \
    wallnut.h \
    zombie.h \
    zombienote.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=

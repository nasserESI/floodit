QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets


CONFIG += console c++17
BUILDS += .

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boardgame.cpp \
    fichier.cpp \
    main.cpp \
    mainwindow.cpp \
    position.cpp \
    square.cpp \
    squaregui.cpp \
    subject.cpp

HEADERS += \
    boardgame.h \
    couleur.h \
    fichier.h \
    mainwindow.h \
    observer.h \
    position.h \
    square.h \
    squaregui.h \
    subject.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ATLIR6_floodIT_56472_fr_BE.ts
    CONFIG += lrelease
    CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

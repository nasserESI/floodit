#include "mainwindow.h"

#include <QApplication>

#include "boardgame.h"

#include <iostream>
#include <cstdio>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*int main(int argc, char *argv[]){
    Boardgame model = Boardgame();
    View myView = View();
    Controller control = Controller(model,myView);
    control.start();
    exit(0);
}*/

#include "initboard.h"
#include "mainwindow.h"
#include "exception"
initBoard::initBoard(model::Boardgame &game,QWidget * window ):game(game),window(window)
{
    game.registerObserver(this);
    createBoard();
    this->startButton=new QPushButton("start");
    this->addWidget(startButton);
    QObject::connect(startButton, SIGNAL(clicked()),this,SLOT(on_startButton_clicked()));
    this->addItem(this->boardGUI);
}
void initBoard::createBoard(){

}

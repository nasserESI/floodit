#include "ui_mainwindow.h"
#include "boardgame.h"
#include "QHBoxLayout"
#include "QGridLayout"
#include "squaregui.h"
#include <iostream>
#include "observer.h"
#ifndef INITBOARD_H
#define INITBOARD_H
using namespace nvs;
using namespace model;
class initBoard : public  QHBoxLayout,public nvs::Observer
{
    Q_OBJECT
private:
    model::Boardgame &game;
    QGridLayout *boardGUI = nullptr;
    QPushButton *startButton =nullptr;
    QGridLayout *playerPiece=nullptr;
    QWidget * window = nullptr;
    std::map<std::string, int> map ;
    const  std::array<model::Couleur,12> Color ={model::Couleur::BLUE,model::Couleur::BROWN,
                                                 model::Couleur::GREEN,model::Couleur::ORANGE,
                                                 model::Couleur::PINK ,model::Couleur::PURPLE,
                                                 model::Couleur::RED,model::Couleur::YELLOW};


public:
    initBoard(model::Boardgame &game,QWidget * window = nullptr);
    void createBoard();
    void createPlayerPiece();
    //virtual void update(const nvs::Subject * subject) override;
    int countPieces();
    void updateBoard();
    void updatePlayerPiece();


public slots:
    void select(view::squareGUI &square);
    void move(view::squareGUI & square);
    void on_startButton_clicked();
};

#endif // INITBOARD_H

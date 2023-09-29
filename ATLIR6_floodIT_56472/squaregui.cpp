#include "squaregui.h"
#include <QRect>
#include <QPaintEvent>
#include <QPainter>
#include <Qcolor>
void squareGUI::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.begin(this);
    painter.setPen (Qt::black);
    switch(this->color){

    case Couleur::BLUE :


        painter.setBrush(QColor (0, 0, 255));
        painter.drawRect(0,0,25,25);
        //this->setStyleSheet("background-color: blue;");

        break;

    case Couleur::GREEN :
        //this->setStyleSheet("background-color: green;");
        painter.setBrush(QColor (0, 204, 0));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::BROWN :
        //this->setStyleSheet("background-color: brown;");
        painter.setBrush(QColor(153, 76, 0));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::ORANGE :
        //this->setStyleSheet("background-color: blue;");
        painter.setBrush(QColor (255, 128, 0));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::PINK :
        //this->setStyleSheet("background-color: pink;");
        painter.setBrush(QColor(255, 0, 255));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::RED :
        //this->setStyleSheet("color: red;");
        painter.setBrush(QColor(255,0,0));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::PURPLE :
        //this->setStyleSheet("color: purple;");
        painter.setBrush(QColor (153, 51, 255));
        painter.drawRect (0,0,25,25);


        break;
    case Couleur::YELLOW :
        //this->setStyleSheet("color: yellow;");
        painter.setBrush(QColor (255, 255, 0));
        painter.drawRect (0,0,25,25);

        break;

    case Couleur::EMPTY:
        break;
    }
    //painter.end();

}
squareGUI::squareGUI(Couleur carre,Position position):color(carre),pos(position)
{
    QPaintEvent event(QRect(0, 0, 25, 25));
    squareGUI::paintEvent(&event);

}
void squareGUI::on_square_pushed(){


}
void squareGUI::mouseClick(){
    emit click(*this);
}
Position squareGUI::getPos()const{
    return this->pos;
}
squareGUI::~squareGUI()
{

}

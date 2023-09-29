#ifndef SQUAREGUI_H
#define SQUAREGUI_H
#include <QPainter>
#include <QWidget>
#include "couleur.h"

#include <QPushButton>
#include <QMouseEvent>
#include "position.h"
using namespace model;
class squareGUI : public QPushButton
{
Q_OBJECT
private:
//QPainter painter;
Couleur color;
//QColor couleur;
//QPaintEvent event;
//QRect rect;
Position pos;
public:
      /**
      * @brief squareGUI définit un carre dans le GUI
      * @param carre c'est la couleur désigné par un entier
      * @param position la position par rapport au GUI
      */
     squareGUI(Couleur carre,Position position);
      /**
      * @brief paintEvent fonction hérité de QPainter
      * @param event
      */
     virtual void paintEvent(QPaintEvent *event)override;
     /**
      * @brief getPos getter de la position du square de la GUI
      * @return un objet de position
      */
     Position getPos()const;
     ~squareGUI();
signals:
     void click(squareGUI &s);
private slots:
     /**
      * @brief on_square_pushed
      * fonction evenementiel qui définit ce qu'il se passe dans le model
      * au moment d'appuyer sur le boutton
      */
     void on_square_pushed();
      /**
      * @brief mouseClick evenement de click
      */
     void mouseClick();

};

#endif // SQUAREGUI_H

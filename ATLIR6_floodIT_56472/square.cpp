#include "square.h"
#include "couleur.h"
#include <iostream>
using namespace model;
using namespace std;
square::square(Couleur color):color(color)
{
    this->color=color;
}
Couleur square::getColor()const{
    return this->color;
}
void square::setColor(Couleur color){
    this->color=color;
}

bool square::operator!=(Couleur color){
    return this->getColor()!=color;
}

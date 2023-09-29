#include "couleur.h"
#include "square.h"
#ifndef POSITION_H
#define POSITION_H

namespace model{
/**
* @brief The Position class gère les positions d'un carré
*/
class Position
{
    int row;
    int column;
public:
    /**
     * @brief Position constructeur de la position
     * @param row abcisse
     * @param column ordonnée
     */
    Position(int row,int column);
    /**
     * @brief getRow retourne la position en abcisse
     * @return un entier
     */
    int getRow()const;
    /**
     * @brief getColumn retourne l'ordonnée par rapport
     * @return un entier
     */
    int getColumn()const;
    /**
     * @brief operator == fonction membre pour comparé l'objet courant avec un autre de même classe
     * @param pos la position avec laquelle on compare la courante
     * @return vrai si row et column sont égaux sinon faux
     */
    bool operator==(Position pos);
};
};
#endif // POSITION_H

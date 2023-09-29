#include "couleur.h"
//#include <QWIdget>
#ifndef SQUARE_H
#define SQUARE_H

namespace model{
class square
{
private:
    Couleur color;
public:
    /**
     * @brief square constructeur essentiel pour définir les caractèristiques
     * d'un carré du plateau
     * @param color par défaut il est vide due à une décision de crée un plateau
     * paralèlle qui enregistre la tâche. mais ça n'a au final pas été fait.
     */
    square(Couleur color = Couleur::EMPTY);
    /**
     * @brief getColor getter de la couleur de la case
     * @return retourne la valeur de l'énumération
     */
    Couleur getColor()const;
    /**
     * @brief setColor setter pour modifier la couleur
     * @param color couleur à installé
     */
    void setColor(Couleur color);
    /**
     * @brief operator != vérifie que les cases soient de couleur différentes
     * @return vrai si c'est le cas, faux si ce n'est pas le cas.
     */
    bool operator!=(Couleur);
};
};
#endif // SQUARE_H

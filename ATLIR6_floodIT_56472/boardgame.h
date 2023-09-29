#include "square.h"
#include <vector>
#include "position.h"
#include <array>
#include "subject.h"
#include <string.h>

#ifndef BOARDGAME_H
#define BOARDGAME_H


namespace model {

class Boardgame :public Subject
{
private:
    int colors;
    int size;
    int attempt;
    std::vector<std::vector<square>> board;
    std::set<Observer *> observers;
public:
    /**
     * @brief Boardgame constructeur de base
     */
    Boardgame();
    /**
     * @brief Boardgame
     * @param size
     * @param couleur
     */
    Boardgame(int size,int couleur);
    /**
     * @brief getNumberOfAttempt : donne le nombre de tentatives
     * @return un entier représentant le nombre de tentatives
     */
    std::string getNumberOfAttempt()const;

    /**
     * @brief initboard : s'occupe de faire le travail du constructeur
     * c'est à dire, crée des cases et les peindres en fonction de l'entier
     * qui est associé à la couleur.
     * @param size : la taille
     * @param couleur la couleur des cases
     */
    void initboard(int size,int couleur);
    /**
     * @brief UpdateColor : prend cinq paramètres : i, j, row, col et newColor.
     * Elle est appelée sur un objet de la classe Boardgame et met à jour la couleur
     * des cases du plateau de jeu à partir de la case de coordonnées (i,j).
     * La nouvelle couleur à appliquer est passée en paramètre avec
     * l'argument newColor.
     * @param i abcisse du point courant
     * @param j ordonnée du point courant
     * @param row abcisse du point selectionné
     * @param column ordonné du point selectionné
     * @param newColor la couleur à appliquer
     */
    void UpdateColor(int i,int j,int row,int column,Couleur newColor);
    /**
     * @brief updateBoard cette méthode s'assure d'abord que la couleur séléctionné est bien différente de
     * celle de la tâche ensuite elle fait appel à updateColor et incrémente le nombre de tentative grace à
     * addAttempt().
     * @param pos la position de la case selectionné
     */
    void updateBoard(Position *pos);
    /**
     * @brief addAttempt incrémente le nombre de tentatives
     */
    void addAttempt();
    /**
     * @brief setColors permet d'installer une couleur pour une case.
     * @param colors la couleur en question
     */
    void setColors(int colors);
    /**
     * @brief getSize donne la taille du plateau
     * @return un entier représentant la taille
     */
    int getSize()const;
    /**
     * @brief color retourne la couleur
     * @return retourne la couleur sous forme d'un entier qui lui corresponds
     */
    int color()const;
    /**
     * @brief getBoard retourne le tableau dynamique de couleur sous forme
     * de tableau d'entier
     * @return le vecteur 2d
     */
    std::vector<std::vector<square>> getBoard()const;
    /**
     * @brief isFinished regarde si toutes les cases ont la même couleur que celle en [0][0]
     * si c'est le cas c'est que le jeux est terminé
     * @return true si c'est terminé, false si ce n'est pas le cas.
     */
    bool isFinished()const;


};
};
#endif // BOARDGAME_H

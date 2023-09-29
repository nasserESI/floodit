#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QString>
#include <string.h>
#include <QFile>
#ifndef FICHIER_H
#define FICHIER_H

/**
 * @brief The Fichier class cette classe gère les données à lire et écrire
 */
class Fichier{
private:
    /**
     * @brief lignes : liste dynamique de données
     */
    std::vector<std::string> lignes;

public:
    /**
     * @brief Fichier constructeur qui par défaut va instancier un objet pour lire et crée le vector de score
     */
    Fichier();
    ~Fichier();
    /**
     * @brief getList retourne la liste des score. elle est disponible malgré la fermeture du fichier après l'instanciation des données.
     * @return vector de score
     */
    std::vector<std::string> getList()const;
    /**
     * @brief writeFile écrit le dernier score à ce jour.
     * il faut redémmarré le jeux pour avoir l'affichage à jour.
     * @param score
     */
    void writeFile(std::string score);
};

#endif // FICHIER_H

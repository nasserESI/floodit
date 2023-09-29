#include "fichier.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <string.h>
#include <qtextstream.h>
#include <QCoreApplication>
#include <fstream>
using namespace std;
Fichier::Fichier()
{
    std::fstream file = std::fstream("monfichier.txt", std::ios::in | std::ios::out);
    string line;
    if(!file.is_open()){
        qCritical()<<"ne sait pas lire";
        qCritical()<<file.exceptions();
    }
    qInfo()<<"lecture du fichier";
    while (getline(file,line)) {
        lignes.push_back(line);
    }
    for(int x = 0 ; x < this->getList().size();x++){
        qInfo()<<" valeur teste : "<<QString::fromStdString(this->getList().at(x));
    }
    qInfo()<<"fin de lecture tout fonctionne";
    file.close();
}

void Fichier::writeFile(std::string score){

    std::ofstream file;
    file.open("monfichier.txt",std::ios::out | std::ios::app);
    if(file.is_open()){

        file<<score<<endl;

        file.close();
    }
}
std::vector<std::string> Fichier::getList()const{
    return this->lignes;
}

Fichier::~Fichier(){

}

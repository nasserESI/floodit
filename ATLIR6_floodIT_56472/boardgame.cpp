#include "boardgame.h"
#include "couleur.h"
#include "square.h"
#include <random>
#include "string.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <QDebug>
#include "string.h"
using namespace std;
using namespace model;
void Boardgame::initboard(int size,int couleur){
    if(couleur>8){
        couleur = 8;
    }
    this->attempt = 0;
    this->board = std::vector<std::vector<square>>(size, std::vector<square>(size));

    for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                             std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> couleur_dis(1, couleur);
            int choix = couleur_dis(gen);
            Couleur c;
            switch (choix) {
            case 1:
                c = Couleur::RED;
                break;
            case 2:
                c = Couleur::BLUE;
                break;
            case 3:
                c = Couleur::YELLOW;
                break;
            case 4:
                c = Couleur::PINK;
                break;
            case 5:
                c = Couleur::GREEN;
                break;
            case 6:
                c = Couleur::ORANGE;
                break;
            case 7:
                c = Couleur::PURPLE;
                break;
            case 8:
                c = Couleur::BROWN;
                break;
            }
            this->board[x][y].setColor(c);
        }
    }

}
int Boardgame::color()const{
    return this->colors;
}
Boardgame::Boardgame(){
    this->attempt = 0;
}
Boardgame::Boardgame(int size,int couleur)
{

        this->attempt = 0;
        this->size=size;
        this->colors=couleur;
        Boardgame::initboard(size,couleur);

}

void Boardgame::setColors(int color){
    this->colors=color;
}
std::string Boardgame::getNumberOfAttempt()const{
    return "nombre de coups : "+std::to_string(this->attempt);
}
int Boardgame::getSize()const{
    return this->size;
}
void Boardgame::addAttempt(){
    this->attempt++;
}

void Boardgame::UpdateColor(int i , int j,int row,int col ,Couleur newColor){

    Couleur clr =board[i][j].getColor();
    board[i][j].setColor(newColor);

    if(j<(int)board.size()-1  && board[i][j+1].getColor()==clr){
        UpdateColor(i,j+1,row,col,newColor);
    }
    if(j>0 && board[i][j-1].getColor()==clr){
        UpdateColor(i,j-1,row,col,newColor);
    }
    if(i<(int)board.size()-1 && board[i+1][j].getColor()==clr){
        UpdateColor(i+1,j,row,col,newColor);
    }
    if(i>0 && board[i-1][j].getColor()==clr){
        UpdateColor(i-1,j,row,col,newColor);
    }

}


std::vector<std::vector<square>> Boardgame::getBoard()const{
    return this->board;
}

void Boardgame::updateBoard(Position *pos){
    if(this->getBoard()[pos->getRow()][pos->getColumn()].getColor()!=this->getBoard()[0][0].getColor()){
        Couleur color = this->board[pos->getRow()][pos->getColumn()].getColor();
        Boardgame::UpdateColor(0,0,pos->getRow(), pos->getColumn(),color);
        addAttempt();
        this->notifyObservers();
    }
}
bool Boardgame::isFinished()const{
    for(int x = 0; x < this->getBoard().size();x++){
        for(int y = 0; y < this->getBoard().size();y++){
            if(this->getBoard()[x][y].getColor()!=this->getBoard()[0][0].getColor()){
                return false;
            }
        }
    }
}


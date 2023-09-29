#include "position.h"
using namespace model;
Position::Position(int row,int column):row(row),column(column)
{

}
bool Position::operator==(Position pos){
    return pos.getRow() ==this->row && pos.getColumn() == this->getColumn();
}
int Position::getRow()const{
    return this->row;
}
int Position::getColumn()const{
    return this->column;
}

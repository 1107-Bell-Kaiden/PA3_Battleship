#include "boat.h"

Boat::Boat() : boatFront(), boatBack(), hits(){
    name = "NULL";
    length = 0;
    hits.fill(false);
}

Boat::Boat(Square f, Square b, string n, int len){
    boatFront = f;
    boatBack = b;
    name = n;
    length = len;
    hits.fill(len);
}

Boat::Boat(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;
    length = rhs.length;
    hits = rhs.hits;
}

Boat::~Boat(){}

Square Boat::getBoatFront() const{
    return boatFront;
}
Square Boat::getBoatBack() const {
    return boatBack;
}

string Boat::getName() const{
    return name;
}

int Boat::getLength() const{
    return length;
}

void Boat::setBoatFront(Square f){
    boatFront = f;
}
void Boat::setBoatBack(Square b){
    boatBack = b;
}

void Boat::setName(string n){
    name = n;
}

//have to change this
bool Boat::isSunk() const{
    return length <= 0;
}

void Boat::hit(int pos) {
    if (pos >= 0 && pos < hits.getCurrentSize()) {
        if(!hits.getElement(pos)) {
            hits.changeElement(pos, true);
            length--;
        }
    } 
}

Boat& Boat::operator =(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;
    length = rhs.length;
    hits = rhs.hits;
    return *this;
}
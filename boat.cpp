#include "boat.h"

Boat::Boat() : boatFront(), boatBack(), hits(){
    name = "NULL";
    hits.fill(false);
}

Boat::Boat(Square f, Square b, string n, int len){
    boatFront = f;
    boatBack = b;
    name = n;
    hits.fill(len);
}

Boat::Boat(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;
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
bool Boat::isSunk(){
    for (int i = 0; i < hits.getCurrentSize(); i++) {
        if (!hits.getElement(i)) {
            return false;
        }
    }
    return true;
}
void Boat::hit(int pos) {
    if (pos >= 0 && pos < hits.getCurrentSize()) {
        hits.changeElement(pos, true);
    }
}

Boat& Boat::operator =(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;
    hits = rhs.hits;
    return *this;
}
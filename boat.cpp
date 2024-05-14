#include "boat.h"

Boat::Boat() : boatFront(), boatBack(){
    name = "NULL";
}

Boat::Boat(Square f, Square b, string n){
    boatFront = f;
    boatBack = b;
    name = n;
}

Boat::Boat(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;
}

Boat::~Boat(){}

Square Boat::getBoatFront(){
    return boatFront;
}
Square Boat::getBoatBack(){
    return boatBack;
}

string Boat::getName(){
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
    //maybe check the ships array, we can set them equal to something when they are hits
    return false; //for compiler
}

Boat& Boat::operator =(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;

    return *this;
}
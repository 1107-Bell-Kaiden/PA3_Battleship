#include "boat.h"

Boat::Boat(){
    boatFront = 0;
    boatBack = 0;
    name = "NULL";
}

Boat::Boat(int f, int b, string n){
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

int Boat::getBoatFront(){
    return boatFront;
}
int Boat::getBoatBack(){
    return boatBack;
}

string Boat::getName(){
    return name;
}

void Boat::setBoatFront(int f){
    boatFront = f;
}
void Boat::setBoatBack(int b){
    boatBack = b;
}

void Boat::setName(string n){
    name = n;
}

bool Boat::isSunk(){
    if (boatFront == 0 && boatBack == 0) {
        return true;
    } else {
        return false;
    }
}

Boat& Boat::operator =(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
    name = rhs.name;

    return *this;
}
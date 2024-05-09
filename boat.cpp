#include "boat.h"

Boat::Boat(){
    boatFront = 0;
    boatBack = 0;
}

Boat::Boat(int f, int b){
    boatFront = f;
    boatBack = b;
}

Boat::Boat(const Boat& rhs){
    boatFront = rhs.boatFront;
    boatBack = rhs.boatBack;
}

Boat::~Boat(){
//    delete [] boat;
}

int Boat::getBoatFront(){
    return boatFront;

}
int Boat::getBoatBack(){
    return boatBack;
}

void Boat::setBoatFront(int f){
    boatFront = f;
}
void Boat::setBoatBack(int b){
    boatBack = b;
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

    return *this;
}
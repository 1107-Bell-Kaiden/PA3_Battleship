#ifndef BOAT_H
#define BOAT_H

#include <iostream>
using namespace std;

#include "square.h"

class Boat {
    Square boatFront;
    Square boatBack;
    string name;

    public:
        Boat();
        Boat(Square, Square, string);
        Boat(const Boat&);

        ~Boat();

        Square getBoatFront();
        Square getBoatBack();
        string getName();

        void setBoatFront(Square);
        void setBoatBack(Square);
        void setName(string);

        bool isSunk();

        Boat& operator =(const Boat& rhs); 
};
#endif
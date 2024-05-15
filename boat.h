#ifndef BOAT_H
#define BOAT_H

#include "square.h"
#include "dynamicArray.h"

class Boat {
    Square boatFront;
    Square boatBack;
    string name;
    DynamicArray<bool> hits;

    public:
        Boat();
        Boat(Square, Square, string, int len);
        Boat(const Boat&);

        ~Boat();

        Square getBoatFront() const;
        Square getBoatBack() const;
        string getName() const;

        void setBoatFront(Square);
        void setBoatBack(Square);
        void setName(string);

        bool isSunk();

        void hit(int);

        Boat& operator =(const Boat& rhs); 
};
#endif
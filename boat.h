#ifndef BOAT_H
#define BOAT_H

#include "square.h"
#include "dynamicArray.h"

class Boat {
    Square boatFront;
    Square boatBack;
    string name;
    int length;
    DynamicArray<bool> hits;

    public:
        Boat();
        Boat(Square, Square, string, int);
        Boat(const Boat&);

        ~Boat();

        Square getBoatFront() const;
        Square getBoatBack() const;
        string getName() const;
        int getLength() const;

        void setBoatFront(Square);
        void setBoatBack(Square);
        void setName(string);

        bool isSunk() const;

        void hit(int);

        Boat& operator =(const Boat& rhs); 
};
#endif
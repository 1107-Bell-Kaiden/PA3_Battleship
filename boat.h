#ifndef BOAT_H
#define BOAT_H

#include <iostream>
using namespace std;


class Boat {
    int boatFront;
    int boatBack;

    public:
        Boat();
        Boat(int, int);
        Boat(const Boat&);

        ~Boat();

        int getBoatFront();
        int getBoatBack();

        void setBoatFront(int);
        void setBoatBack(int);

        bool isSunk();

        Boat& operator =(const Boat& rhs); 
};

#endif
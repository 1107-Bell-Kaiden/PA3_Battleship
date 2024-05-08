#indef BOAT_H
#define BOAT_H

#include <stdio.h>
using namespace std;


Class Boat {
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
}

#endif
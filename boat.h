#ifndef BOAT_H
#define BOAT_H

#include <iostream>
using namespace std;

//we can't store the front/back as an int anymore, could use struct possibly?
//not super familiar w them though, not sure where theyd go or how exactly it'd work
//smth like this:

/*struct LetterNumber {
    char letter;
    int number;
};

int main() {
    // Creating an instance of LetterNumber
    LetterNumber ln;
    
    // Assigning values
    ln.letter = 'A';
    ln.number = 1;
    
    // Accessing values
    std::cout << "Letter: " << ln.letter << ", Number: " << ln.number << std::endl;
    
    return 0;
}*/

class Boat {
    int boatFront;
    int boatBack;
    string name;

    public:
        Boat();
        Boat(int, int, string);
        Boat(const Boat&);

        ~Boat();

        int getBoatFront();
        int getBoatBack();
        string getName();

        void setBoatFront(int);
        void setBoatBack(int);
        void setName(string);

        bool isSunk();

        Boat& operator =(const Boat& rhs); 
};

#endif
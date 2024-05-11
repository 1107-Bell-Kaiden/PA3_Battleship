#ifndef PLAYER_H
#define PLAYER_H

#include "boat.h"
#include "dynamicArray.h"

class Player {
    protected:
        DynamicArray<int>& playerBoard;
        DynamicArray<int>& opponentBoard;
        DynamicArray<Boat> ships; // Yeah make this dynamically allocated, cuz the ships technically do change.
        DynamicArray<int> guesses;
        bool turn;
        string name;

    public:
        Player();
        Player(string, string, Boat*, bool, string, int, int);
        Player(const Player&);

        ~Player();
        Player& operator=(const Player&); // <- Using rule of 3, we have to add this aswell

        // Getters
        DynamicArray<int> getPlayerBoard(); // I think we change all the boards to ints (2D arrays) instead.
        DynamicArray<int> getOpponentBoard();
        //DynamicArray<Boat> getShips();
        bool getTurn();
        string getName();

        // Setters
        void setTurn(bool);
        void setName(string);

        //Methods
        virtual void takeTurn(); // <- Should then be a virtual function with base implementation
};

#endif
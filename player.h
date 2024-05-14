#ifndef PLAYER_H
#define PLAYER_H

#include "helpers.h"
#include "boat.h"
#include "dynamicArray.h"
#include "square.h"

class Player {
    protected:
        DynamicArray<int> playerBoard;
        DynamicArray<int> opponentBoard;
        DynamicArray<Boat> ships; 
        DynamicArray<Square> guesses;
        bool turn;
        string name;

    public:
        Player();
        Player(DynamicArray<int>, DynamicArray<int>, DynamicArray<Boat>, DynamicArray<Square>, bool, string);
        Player(const Player&);

        ~Player();
        Player& operator=(const Player&); // <- Using rule of 3, we have to add this aswell

        // Getters
        DynamicArray<int>& getPlayerBoard(); // I think we change all the boards to ints (2D arrays) instead.
        DynamicArray<int>& getOpponentBoard();
        DynamicArray<Boat>& getShips();
        DynamicArray<Square>& getGuesses();
        bool getTurn();
        string getName();

        // Setters
        void setPlayerBoard(DynamicArray<int>&);
        void setOpponentboard(DynamicArray<int>&);
        void setShips(DynamicArray<Boat>&);
        void setGuesses(DynamicArray<Square>&);
        void setTurn(bool);
        void setName(string);

        //Methods
        bool isSquareOccupied(const Square& s) const;
        int convertSquaresToIndex(const Square& s) const;
        void occupuySquare(const Square& s);

        virtual void placeShipsRandom();
        virtual void takeTurn(Player); // <- Should then be a virtual function with base implementation
};

#endif
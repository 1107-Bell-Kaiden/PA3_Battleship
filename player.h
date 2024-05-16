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
        DynamicArray<int>& getPlayerBoard();
        const DynamicArray<int>& getPlayerBoard() const;
         
        DynamicArray<int>& getOpponentBoard();
        Boat& getBoat(int);
        string getShipTypeName(int);
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
        void occupuySquare(const Square& s, int);

        int calcPosOnBoat(int, const Square&);

        void markHit(const Square&, DynamicArray<int>&);
        void markMiss(const Square&, DynamicArray<int>&);

        bool checkWin() const;

        //virtual void placeShipsRandom();
        virtual void takeTurn(AiPlayer&); // <- Should then be a virtual function with base implementation
};

#endif
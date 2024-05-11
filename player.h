#ifndef PLAYER_H
#define PLAYER_H

#include "boat.h"

class Player {
    protected:
        string player1_board;
        string opponent_board;
        Boat* ships; // Yeah make this dynamically allocated, cuz the ships technically do change.
        bool turn;
        string name;

        int numShips, maxShips; // <- Keep here

    public:
        Player();
        Player(string, string, Boat*, bool, string, int, int);
        Player(const Player&);

        ~Player();
        Player& operator=(const Player&); // <- Using rule of 3, we have to add this aswell

        // Getters
        string getPlayer1_Board(); // I think we change all the boards to ints (2D arrays) instead.
        string getOpponent_Board();
        Boat* getShips();
        bool getTurn();
        string getName();

        // Setters
        void setPlayer1_Board(string);
        void setOpponent_Board(string);
        void setTurn(bool);
        void setName(string);

        void addShip(Boat); // <- Dynamically allocating ships but we never have to add a ship correct?

        //Methods
        void placeShips();
        virtual void takeTurn(); // <- Should then be a virtual function with base implementation

        void removeShip(); // <- Ye add this one aswell


};

#endif
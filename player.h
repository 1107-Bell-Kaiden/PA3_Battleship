#ifndef PLAYER_H
#define PLAYER_H

#include "boat.h"

class Player {
    protected:
        string player1_board;
        string opponent_board;
        Boat* ships; //would we make this a dynamicArray?
        bool turn;
        string name;

        //idk if we have to dynamically allocate ships or not.
        int numShips;
        int maxShips;

    public:
        Player();
        Player(string, string, Boat*, bool, string, int, int);
        Player(const Player&);

        ~Player();
        Player& operator=(const Player&);

        // Getters
        string getPlayer1_Board();
        string getOpponent_Board();
        Boat* getShips();
        bool getTurn();
        string getName();

        // Setters
        void setPlayer1_Board(string);
        void setOpponent_Board(string);
        void setTurn(bool);
        void setName(string);

        //void setShips(Boat);
        //void addShip(Boat); ?

        //Methods
        void placeShips();
        void takeTurn();

        //void removeShip(); ?
};

#endif
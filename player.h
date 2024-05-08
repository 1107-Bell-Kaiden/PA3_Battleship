#ifndef PLAYER_H
#define PLAYER_H

#include "boat.h"

class Player {
    string player1_board;
    string opponent_board;
    Boat* ships;
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

        // Getters
        string getPlayer1_Board();
        string getOpponent_Board();
        Boat* getShips();
        bool getTurn();

        string getName();

        // Setters
        void setPlayer1_Board(string);
        void setOpponent_Board(string);

        // void setShips(Boat);
        //
        void setTurn(bool);

        void setName(string);
};

#endif
#ifndef HELPERS_H
#define HELPERS_H

#include "aiPlayer.h"
#include "dynamicArray.h"

class Helpers {
    public:
        void startGame(Player&, AiPlayer&);
        void placeShips();
        void playRound();
        void displayBoards(Player&);
        void updateBoard(int, int);
        bool checkHit(string, int, int);
        bool checkGuess(string, int, int);
        bool checkWin();
};
#endif
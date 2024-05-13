#ifndef HELPERS_H
#define HELPERS_H

#include "aiPlayer.h"

int startGame(Player&, AiPlayer&);
void placeShips(Player&);
bool checkShips(Square, Square);
void initShips(Square, Square);
bool playRound(Player&, AiPlayer&, int&);
void displayBoards(Player&);
bool checkHit(Square);
bool checkGuess(Square);
bool checkWin();

#endif
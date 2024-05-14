#ifndef HELPERS_H
#define HELPERS_H

#include "player.h"
#include "aiPlayer.h"

int startGame(Player&, AiPlayer&);
bool isValidSquare(const Square&, const Player&);
void placeShips(Player&);
bool checkShips(Square, Square, const Player&);
void initShips(Square, Square, Player&);
bool playRound(Player&, AiPlayer&, int&);
void displayBoards(Player&);
bool checkHit(Square);
bool checkGuess(Square);
bool checkWin();

#endif
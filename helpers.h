#ifndef HELPERS_H
#define HELPERS_H

#include "aiPlayer.h"
#include "dynamicArray.h"

#include <time.h>
#include <stdlib.h>

int startGame(Player&, AiPlayer&);
void placeShips(Player);
bool checkShips(char, int, char, int);
void initShips(char, int, char, int);
bool playRound(Player, AiPlayer, int*);
void displayBoards(Player&);
bool checkHit(string, int, int);
bool checkGuess(string, int, int);
bool checkWin();

#endif
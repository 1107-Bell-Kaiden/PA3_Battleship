#ifndef HELPERS_H
#define HELPERS_H

#include "aiPlayer.h"
#include "dynamicArray.h"

void startGame(Player&, AiPlayer&);
void placeShips(Player);
bool checkShips(char, int, char, int);
void initShips(char, int, char, int);
void playRound();
void displayBoards(Player&);
void updateBoard(int, int);
bool checkHit(string, int, int);
bool checkGuess(string, int, int);
bool checkWin();

#endif
#ifndef HELPERS_H
#define HELPERS_H

#include "dynamicArray.h"

class Player;
class AiPlayer;
class Square;

int startGame(Player&, AiPlayer&);
bool isValidSquare(const Square&, const Player&);
void placeShips(Player&);
char displayBoardValue(int);
bool checkShips(Square, Square, const Player&, int);
void initShips(Square, Square, Player&, int);
bool playRound(Player&, AiPlayer&, int&);
void displayPlayerBoard(Player&);
void displayOpponentBoard(AiPlayer&);
void updateBoard(Square, bool, DynamicArray<int>&);
bool checkHit(Square, const Player&);
bool checkGuess(Square, const DynamicArray<Square>&);
bool checkWin(const Player &p);

#endif
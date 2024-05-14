#ifndef HELPERS_H
#define HELPERS_H

#include "dynamicArray.h"

class Player;
class AiPlayer;
class Square;

int startGame(Player&, AiPlayer&);
bool isValidSquare(const Square&, const Player&);
void placeShips(Player&);
bool checkShips(Square, Square, const Player&);
void initShips(Square, Square, Player&);
bool playRound(Player&, AiPlayer&, int&);
void displayBoards(Player&);
void updateBoard(Square, bool, DynamicArray<Square>&);
bool checkHit(Square, const Player&);
bool checkGuess(Square, DynamicArray<Square>&);
bool checkWin();

#endif
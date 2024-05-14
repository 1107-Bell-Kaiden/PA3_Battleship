#include "aiPlayer.h"

void AiPlayer::placeShipsRandom(){
    srand(time(nullptr));
    DynamicArray<int> shipSizes;
    shipSizes.addItemToArray(5); // Carrier
    shipSizes.addItemToArray(4); // Battleship
    shipSizes.addItemToArray(3); // Crusier
    shipSizes.addItemToArray(3); // Submarine
    shipSizes.addItemToArray(2); // Destroyer

    DynamicArray<string> shipNames;
    shipNames.addItemToArray("Carrier");
    shipNames.addItemToArray("Battleship");
    shipNames.addItemToArray("Crusier");
    shipNames.addItemToArray("Submarine");
    shipNames.addItemToArray("Destroyer");

    int numberShips = shipSizes.getCurrentSize();

    for(int i = 0; i < numberShips; i++) {
        bool placed = false;
        while (!placed) {
            int startRow = rand() % 10 + 'A';
            int startCol = rand() % 10 + 1;
            bool horizontal = rand() % 2 == 0;

            Square start(startRow, startCol);
            Square end = start;

            if (horizontal) {
                end.col += shipSizes.getElement(i) -1;
            } else {
                end.row += shipSizes.getElement(i) -1;
            }
            if (checkShips(start, end, *this)) {
                initShips(start, end, *this);
                placed = true;
            }
        }
    }
}


void AiPlayer::takeTurn(Player& p){
    return;
}
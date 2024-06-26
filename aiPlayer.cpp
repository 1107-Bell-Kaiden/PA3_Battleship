#include "aiPlayer.h"

void AiPlayer::placeShipsRandom(){
    srand(time(nullptr));
    DynamicArray<int> shipSizes;
    shipSizes.addItemToArray(5); // Carrier
    shipSizes.addItemToArray(4); // Battleship
    shipSizes.addItemToArray(3); // Destroyer
    shipSizes.addItemToArray(3); // Submarine
    shipSizes.addItemToArray(2); // Patrol

    DynamicArray<int> shipTypes;
    shipTypes.addItemToArray(1); // Carrier
    shipTypes.addItemToArray(2); // Battleship
    shipTypes.addItemToArray(3); // Destroyer
    shipTypes.addItemToArray(4); // Submarine
    shipTypes.addItemToArray(5); // Patrol

    int numberShips = shipSizes.getCurrentSize();

    for(int i = 0; i < numberShips; i++) {
        bool placed = false;
        while (!placed) {
            int startRow = 'A' + rand() % 10;
            int startCol = 1 + rand() % 10;
            bool horizontal = rand() % 2 == 0;

            Square start(startRow, startCol);
            Square end = start;

            if (horizontal) {
                end.col += shipSizes.getElement(i) -1;
            } else {
                end.row += shipSizes.getElement(i) -1;
            }
            if (checkShips(start, end, *this, shipTypes.getElement(i))) {
                initShips(start, end, *this, shipTypes.getElement(i));
                placed = true;
            }
        }
    }
}


void AiPlayer::takeTurn(Player& opponent){
    srand(time(0));

    Square square;
    bool guess, hit, sunk;

    do {
        // Random square selection
        square.row = 'A' + rand() % 10;
        square.col = 1 + rand() % 10;

        // Check to make sure guess is valid
        guess = checkGuess(square, guesses);
    } while (!guess); 

    guesses.addItemToArray(square);

    hit = checkHit(square, opponent); // Check if the guess is a hit

    cout << "Shot at: " << square.row << square.col << (hit ? " hit" : " miss") << endl;

    if (hit) {
        int shipType = opponent.getPlayerBoard().getArray()[convertSquaresToIndex(square)];
        cout << "The enemy hit your " << opponent.getShipTypeName(shipType) << "! Brace!!" << endl;

        markHit(square, opponent.getPlayerBoard());

        if (shipType >= 1 && shipType <= 5) { // Check if the ship is a valid type
            Boat& hitOnBoat = opponent.getBoat(shipType);
            int posOnBoat = calcPosOnBoat(shipType, square);
            hitOnBoat.hit(posOnBoat);


            if(hitOnBoat.isSunk()){
                cout << "Congratulations, you sunk the opponent's " << opponent.getShipTypeName(shipType) << "!! Sucks to be them!" << endl;
            }

            } else {
                cout << "Error: Unexpected ship val" << endl;
            }
    } else {
        markMiss(square, opponent.getPlayerBoard());
        cout << "Ha, the enemy missed. They must be blind!" << endl;
        cout << endl;
    }
    updateBoard(square, hit, opponent.getPlayerBoard());
}

DynamicArray<int>& AiPlayer::getPlayerBoard() {
    return playerBoard;
}

const DynamicArray<int>& AiPlayer::getPlayerBoard() const{
    return playerBoard;
}

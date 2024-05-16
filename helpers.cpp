#include "helpers.h"
#include "boat.h"
#include "player.h"
#include "aiPlayer.h"
#include "square.h"

int startGame(Player& p, AiPlayer& a){
    string name;
    int random = 0;

    cout << "Enter your name: ";
    cin >> name;
    p.setName(name);

    //place ai ships
    a.placeShipsRandom();
    p.setOpponentboard(a.getPlayerBoard());

    //to place user ships, have them select a beginning and end point for each ship
    placeShips(p);

    //randomly decide who goes first (pick between 1 & 2), implement later
    random = rand() % 2 + 1;

    return random;
}

void placeShips(Player& p){
    Square start;
    Square end;
    bool result;
    DynamicArray<char> shipTypes; 
    shipTypes.addItemToArray(1); // Carrier
    shipTypes.addItemToArray(2); // Battleship
    shipTypes.addItemToArray(3); // Destroyer
    shipTypes.addItemToArray(4); // Submarine
    shipTypes.addItemToArray(5); // Patrol Boat

    //Carrier
    displayPlayerBoard(p);
    cout << "To place your Carrier (5 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end; 

        result = checkShips(start, end, p, shipTypes.getElement(0));
    }while(result == false);
    initShips(start, end, p, shipTypes.getElement(0));
    system("clear");

    //Battleship
    displayPlayerBoard(p);
    cout << "To place your Battleship (4 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p, shipTypes.getElement(1));
    }while(result == false);
    initShips(start, end, p, shipTypes.getElement(1));
    system("clear");

    //Destroyer
    displayPlayerBoard(p);
    cout << "To place your Destroyer (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p, shipTypes.getElement(2));
    }while(result == false);
    initShips(start, end, p, shipTypes.getElement(2));
    system("clear");

    //Submarine
    displayPlayerBoard(p);
    cout << "To place your Submarine (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p, shipTypes.getElement(3));
    }while(result == false);
    initShips(start, end, p, shipTypes.getElement(3));
    system("clear");

    //Patrol Boat
    displayPlayerBoard(p);
    cout << "To place your Patrol Boat (2 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p, shipTypes.getElement(4));
    }while(result == false);
    initShips(start, end, p, shipTypes.getElement(4));
    system("clear");
}

char displayBoardValue(int val) {
    switch(val) {
        case 0: return '~'; // water
        case 1: return 'C'; // carrier
        case 2: return 'B'; // battleship
        case 3: return 'D'; // destroyer
        case 4: return 'S'; // sub
        case 5: return 'P'; // patrol boat
        case 10: return 'X'; // hit
        case 11: return 'M'; // miss
        default: return '?'; // unknown val
    }
}

bool isValidSquare(const Square& square, const Player& player){
    if(square.row < 'A' || square.row > 'J' || square.col < 1 || square.col > 10) {
        return false;
    }
    return !player.isSquareOccupied(square);
}

//checks the validity of the ship placement
bool checkShips(Square s, Square e, const Player& player, int shipType) {
    
    // Mark down expected length based on ship
    int expectedLen = 0;

    if (s.row == e.row) {
        expectedLen = e.col - s.col + 1;
    } else if (s.col == e.col) {
        expectedLen = e.row - s.row + 1;
    } else {
        cout << "Invalid ship placement." << endl;
        return false;
    }

    // Then Check ship length
    int shipLen = 0;
    switch (shipType) {
        case 1: 
            shipLen = 5;
            break;
        case 2:
            shipLen = 4;
            break;
        case 3:
            shipLen = 3;
            break;
        case 4:
            shipLen = 3;
            break;
        case 5:
            shipLen = 2;
            break;
        default:
            cout << "Invalid ship type." << endl;
            return false;
    }
    if (expectedLen != shipLen) {
        cout << "Ship must be exactly: " << shipLen << " spaces long." << endl;
        return false;
    }



    // Finally, check if the ships placement is correct (Horizontal/Vertical)
    if (s.row == e.row) {  // Horizontal
        if (e.col < s.col) swap(s.col, e.col);
        // Iterate through columns
        for (int col = s.col; col <= e.col; ++col) {
            if (!isValidSquare(Square{s.row, col}, player)) return false;
        }
    } else if (s.col == e.col) {  // Vertical
        if (e.row < s.row) swap(s.row, e.row);
        // Iterate through rows
        for (char row = s.row; row <= e.row; ++row) {
            if (!isValidSquare(Square{row, s.col}, player)) return false;
        }
    } else {  // Not in a straight line (invalid placement)
        cout << "Invalid ship placement." << endl;
        return false;
    }



    return true;
}

//places the ships after checked in the ships array
void initShips(Square s, Square e, Player& player, int shipType){
    if (s.row == e.row) {
        if (e.col < s.col) swap(s.col, e.col);
        for (int col = s.col; col <= e.col; ++col) {
            player.occupuySquare(Square{s.row,col}, shipType);
        }
    } else if (s.col == e.col) {
        if (e.row < s.row) swap(s.row, e.row);
        for (char row = s.row; row <= e.row; row++){
            player.occupuySquare(Square{row, s.col}, shipType);
        }
    }
}

//gameloop function
bool playRound(Player& p, AiPlayer& a, int& turn){
    if (turn == 1) {
        // Players Turn
        p.takeTurn(a);
        if (a.checkWin()) {
            return true;
        }
        turn = 2;
    } else if (turn == 2) {
        //AI's turn
        a.takeTurn(p);
        if (p.checkWin()){
            return true;
        }
        turn = 1;
    }
    return false;
}

void displayPlayerBoard(Player& p){
    DynamicArray<int> playerBoard = p.getPlayerBoard();

    cout << "Player's Board: " << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << (char)('A' + i) << " ";
        for(int j = 0; j < 10; j++) {
            cout << displayBoardValue(playerBoard.getElement(i*10+j)) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayOpponentBoard(AiPlayer& p) {
    DynamicArray<int>& opponent_board = p.getPlayerBoard();

    cout << "Opponent Board: " << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << (char)('A' + i) << " ";
        for(int j = 0; j < 10; j++) {
            int val = opponent_board.getElement(10 * i+ j);
            if (val == 10 || val == 11) {
                cout << displayBoardValue(val) << " ";
            } else {
                cout << "~ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// updates after each square selection for hit or miss
void updateBoard(Square s, bool hit, DynamicArray<int>& board){
    //update board with hit/miss
    int index = (s.row - 'A') * 10 + (s.col - 1);

    if (index >= 0 && index < board.getCurrentSize()) {
        if (hit) {
            board.changeElement(index, 10);
        } else {
            board.changeElement(index, 11);
    }
    }
}

//checks if player hit ship
bool checkHit(Square s, const Player& player){
    return player.isSquareOccupied(s);
}

//checks if guess is valid
bool checkGuess(Square s, const DynamicArray<Square>& g){ //g for guesses
    if (s.row < 'A' || s.row > 'J' || s.col < 1 || s.col >  10) {
        cout << "Invalid guess." << endl;
        return false;
    }


    for (int i = 0; i < g.getCurrentSize(); i++) {
        if (g.getElement(i) == s) {
            cout << "Invalid Guess." << endl;
            return false;
        }
    }
    return true;
}


bool checkWin(const Player &p){
    return p.checkWin();
}
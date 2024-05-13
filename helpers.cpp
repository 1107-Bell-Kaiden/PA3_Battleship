#include "helpers.h"
#include "player.h"

int startGame(Player p1, AiPlayer ai){
    string name;
    int rand;

    cout << "Enter your name: ";
    cin >> name;
    p1.setName(name);

    //place ai ships
    ai.placeShipsRandom();

    //to place user ships, have them select a beginning and end point for each ship
    placeShips(p1);

    //randomly decide who goes first (pick between 1 & 2), implement later

    return rand;
}

void placeShips(Player player){
    char startRow, endRow;
    int startCol, endCol;
    bool result;

    //Carrier
    displayBoards(player);
    cout << "To place your Carrier (5 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start (row): ";
        cin >> startRow;
        cout << "   Start (col): ";
        cin >> startCol;

        cout << "   End (row): ";
        cin >> endRow;
        cout << "   End (col): ";
        cin >> endCol;
        
        result = checkShips(startRow, startCol, endRow, endCol);
    }while(result == false);
    initShips(startRow, startCol, endRow, endCol);
    system("clear");

    //Battleship
    displayBoards(player);
    cout << "To place your Battleship (4 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start (row): ";
        cin >> startRow;
        cout << "   Start (col): ";
        cin >> startCol;

        cout << "   End (row): ";
        cin >> endRow;
        cout << "   End (col): ";
        cin >> endCol;
        
        result = checkShips(startRow, startCol, endRow, endCol);
    }while(result == false);
    initShips(startRow, startCol, endRow, endCol);
    system("clear");

    //Destroyer
    displayBoards(player);
    cout << "To place your Destroyer (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start (row): ";
        cin >> startRow;
        cout << "   Start (col): ";
        cin >> startCol;

        cout << "   End (row): ";
        cin >> endRow;
        cout << "   End (col): ";
        cin >> endCol;
        
        result = checkShips(startRow, startCol, endRow, endCol);
    }while(result == false);
    initShips(startRow, startCol, endRow, endCol);
    system("clear");

    //Submarine
    displayBoards(player);
    cout << "To place your Submarine (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start (row): ";
        cin >> startRow;
        cout << "   Start (col): ";
        cin >> startCol;

        cout << "   End (row): ";
        cin >> endRow;
        cout << "   End (col): ";
        cin >> endCol;
        
        result = checkShips(startRow, startCol, endRow, endCol);
    }while(result == false);
    initShips(startRow, startCol, endRow, endCol);
    system("clear");

    //Patrol Boat
    displayBoards(player);
    cout << "To place your Patrol Boat (2 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start (row): ";
        cin >> startRow;
        cout << "   Start (col): ";
        cin >> startCol;

        cout << "   End (row): ";
        cin >> endRow;
        cout << "   End (col): ";
        cin >> endCol;
        
        result = checkShips(startRow, startCol, endRow, endCol);
    }while(result == false);
    initShips(startRow, startCol, endRow, endCol);
    system("clear");

}

//checks the validity of the ship placement
bool checkShips(char srw, int scl, char erw, int ecl){
     if (rw >= 0 && rw < 10 && cl >= 0 && cl < 10) {
        updateBoard(rw, cl);
        return true;
    } else {
        cout << "Invalid ship placement" << endl;
        return false;
    }

}

//places the ships after checked in the ships array
void initShips(char srw, int scl, char erw, int ecl){

}

//gameloop function
bool playRound(Player p, AiPlayer a, int* turn){
    bool win;
    switch(*turn){
        case 1: 
            p.takeTurn(p);
            win = checkWin();
            if(win){
                return true;
            }
            *turn++;
            break;
        case 2:
            a.takeTurn(a);
            win = checkWin();
            if(win){
                return true;
            }
            *turn--;
            break;
        default:
            return 0;
            break;
    }
    return false;
}

void displayBoards(Player& player){
    DynamicArray<int> playerBoard = player.getPlayerBoard();
    DynamicArray<int> opponent_board = player.getOpponentBoard();
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << opponent_board.getArray()[i*10 +j];
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "------------------------" << endl;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << playerBoard.getArray()[i*10+j];
        }
        cout << endl;
    }
    cout << endl;
}

//updates after each square selection for hit or miss
void updateBoard(int rw, int cl){
    //update board with ship placement



}

//checks if player hit ship
bool checkHit(string, int, int){

}

//checks if guess is valid
bool checkGuess(string, int, int){

}

//checks if win conditions are met
bool checkWin(){
    
}
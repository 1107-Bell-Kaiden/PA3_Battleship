#include "helpers.h"

int startGame(Player& p, AiPlayer& a){
    string name;
    int random = 0;

    cout << "Enter your name: ";
    cin >> name;
    p.setName(name);

    //place ai ships
    a.placeShipsRandom();

    //to place user ships, have them select a beginning and end point for each ship
    placeShips(p);

    //randomly decide who goes first (pick between 1 & 2), implement later

    return random;
}

void placeShips(Player& p){
    Square start;
    Square end;
    bool result;

    //Carrier
    displayBoards(p);
    cout << "To place your Carrier (5 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end);
    }while(result == false);
    initShips(start, end);
    system("clear");

    //Battleship
    displayBoards(p);
    cout << "To place your Battleship (4 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end);
    }while(result == false);
    initShips(start, end);
    system("clear");

    //Destroyer
    displayBoards(p);
    cout << "To place your Destroyer (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end);
    }while(result == false);
    initShips(start, end);
    system("clear");

    //Submarine
    displayBoards(p);
    cout << "To place your Submarine (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end);
    }while(result == false);
    initShips(start, end);
    system("clear");

    //Patrol Boat
    displayBoards(p);
    cout << "To place your Patrol Boat (2 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end);
    }while(result == false);
    initShips(start, end);
    system("clear");

}

//checks the validity of the ship placement
bool checkShips(Square s, Square e){ //s = start, e = end
    /*if (rw >= 0 && rw < 10 && cl >= 0 && cl < 10) {
        updateBoard(rw, cl);
        return true;
    } else {
        cout << "Invalid ship placement" << endl;
        return false;
    }*/

}

//places the ships after checked in the ships array
void initShips(Square s, Square e){

}

//gameloop function
bool playRound(Player& p, AiPlayer& a, int& turn){
    bool win;
    switch(turn){
        case 1: 
            p.takeTurn(p);
            win = checkWin();
            if(win){
                return true;
            }
            turn++;
            break;
        case 2:
            a.takeTurn(a);
            win = checkWin();
            if(win){
                return true;
            }
            turn--;
            break;
        default:
            return 0;
            break;
    }
    return false;
}

void displayBoards(Player& p){
    DynamicArray<int> playerBoard = p.getPlayerBoard();
    DynamicArray<int> opponent_board = p.getOpponentBoard();
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
void updateBoard(Square s){
    //update board with hit/miss

}

//checks if player hit ship
bool checkHit(Square s){

}

//checks if guess is valid
bool checkGuess(Square s, DynamicArray<Square> g){ //g for guesses

}

//checks if win conditions are met
bool checkWin(){
    
}
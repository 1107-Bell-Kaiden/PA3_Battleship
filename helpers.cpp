#include "helpers.h"
#include "player.h"

void startGame(Player p1, AiPlayer ai){
    string name;

    cout << "Enter your name: ";
    cin >> name;
    p1.setName(name);
    
    displayBoards(ai);

    //place ai ships
    ai.placeShipsRandom();
    //to place user ships, have them select a beginning and end point for each ship
}

void getShipsInput(){
    int start, end;
    bool result;

    //Carrier
    cout << "To place your Carrier ship (5 squares), select a starting and ending square for it." << endl;
    cout << "-(Enter the row first, followed by the column, not separated by a space. For example, if I want to place the start of my ship at row 2 col 3, I would enter '23'.)-" << endl;
    do{
        cout << "   Start: ";
        cin >> start;
        result = checkBoard()
    }while();
    do{
        cout << "   End: ";
        //cin end
    }while();
    //clear

    //Battleship


    
}

void playRound(){

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


bool checkBoard(int rw, int cl){
    if (rw >= 0 && rw < 10 && cl >= 0 && cl < 10) {
        updateBoard(rw, cl);
        return true;
    } else {
        cout << "Invalid ship placement" << endl;
        return false;
    }

}

void updateBoard(int rw, int cl){
    //update board with ship placement



}

bool checkHit(string, int, int){

}

bool checkGuess(string, int, int){

}

bool checkWin(){
    
}
// Programming Assignment 4 - Battleship
// Authors: Jack Owens, Kaiden Bell
// Date: 5-15-2024

#include "aiPlayer.h"
#include "dynamicArray.h"
#include "helpers.h"

int main(){
    Player player1;
    AiPlayer player2;
    int choice;

    cout << "--BATTLESHIP--" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit Program" << endl << endl;

    cin >> choice;

    switch(choice){
        case 1:
            startGame(player1, player2);
            break;
        case 2:
            return 0;
            break;
        default:
            cout << "Invalid Selection. Exiting program..." << endl;
            return 0;
            break;
    }
}
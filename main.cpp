// Programming Assignment 4 - Battleship
// Authors: Jack Owens, Kaiden Bell
// Date: 5-15-2024

#include "helpers.h"
#include "aiPlayer.h"
#include "dynamicArray.h"

int main(){
    Player player;
    AiPlayer ai;
    int choice;
    int turn;
    bool win = false;

    cout << "--BATTLESHIP--" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit Program" << endl << endl;

    cin >> choice;

    switch(choice){
        case 1:
            turn = startGame(player, ai); // Intialize game start. Who goes first, and placing ships.

            do{
                win = playRound(player, ai, turn);
            }while(!win);
            break;

        case 2:
            return 0;
        default:
            cout << "Invalid Selection. Exiting program..." << endl;
            return 0;
            break;
    }
    if (turn == 1) {
        // AI Wins!
        cout << "All your ships have been sunk. Good luck next time, if you don't drown." << endl << endl;
    } else {
        // Player wins
        cout << "You have sunk all of your opponent's ships. Maybe you'll get a promotion." << endl << endl;
    }
    return 0;
}
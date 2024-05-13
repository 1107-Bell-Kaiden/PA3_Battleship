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
    bool win;

    cout << "--BATTLESHIP--" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit Program" << endl << endl;

    cin >> choice;

    switch(choice){
        case 1:
            turn = startGame(player, ai); //this shows up as an error only sometimes not sure whats up with that, could have to do with &

            do{
                win = playRound(player, ai, turn); //same here
            }while(win == false);
            switch(turn){
                case 1:
                    //player wins
                    cout << "You have sunk all of your opponent's ships. Maybe you'll get a promotion." << endl << endl;
                    cout << "YOU WIN!!" << endl;
                    break;
                case 2:
                    //ai wins
                    cout << "All of your ships have been sunk. Good luck next time, if you don't drown." << endl << endl;
                    cout << "YOU LOSE!!" << endl;
                    break;
                default:
                    return 0;
                    break;
            }
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
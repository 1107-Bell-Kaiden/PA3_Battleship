#include "player.h"

Player::Player(){

}

Player::Player(string pb, string ob, Boat* sh, bool t, string nm, int n, int max){
    numShips = n;
    maxShips = max;

    player1_board = pb;
    opponent_board = ob;
    ships = new Boat[maxShips];

    for (int i = 0; i < numShips; i++) {
        ships[i] = sh[i];
    }

    turn = t;
    name = nm;
}

Player::Player(const Player&){

}
#include "player.h"

Player::Player(){
    playerBoard = new int[100]; // 10x10 Board
    opponentBoard = new int[100]; // 10x10 Board    

    ships = new Boat[5];

    turn = false;
    name = "NONE";
}

Player::Player(string pb, string ob, Boat* sh, bool t, string nm){
    playerBoard = pb;
    opponentBoard = ob;
    ships = new Boat[5];

    for (int i = 0; i < 5; i++) {
        ships[i] = sh[i];
    }

    turn = t;
    name = nm;
}

Player::Player(const Player& rhs){
    playerBoard = rhs.playerBoard;
    opponentBoard = rhs.opponentBoard;
    ships = new Boat[5];

    for (int i = 0; i < 5; i++) {
        ships[i] = rhs.ships[i];
    }

    turn = rhs.turn;
    name = rhs.name;
}

Player::~Player(){
    delete[] playerBoard;
    delete[] opponentBoard;

}

Player& Player::operator=(const Player& rhs){
    playerBoard = rhs.playerBoard;
    opponentBoard = rhs.opponentBoard;
    ships = new Boat[5];

    for (int i = 0; i < 5; i++) {
        ships[i] = rhs.ships[i];
    }

    turn = rhs.turn;
    name = rhs.name;
    
    return *this;
}

DynamicArray<int>& Player::getPlayerBoard(){
    return playerBoard;
}

DynamicArray<int>& Player::getOpponentBoard(){
    return opponentBoard;
}

DynamicArray<Boat> Player::getShips(){
    return ships;
}

bool Player::getTurn(){
    return turn;
}

string Player::getName(){
    return name;
}

void Player::setTurn(bool t){
    turn = t;
}

void Player::setName(string nm){
    name = nm;   
}
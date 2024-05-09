#include "player.h"

Player::Player(){
    numShips = 0;
    maxShips = 5; //idk

    player1_board = "NONE"; //idk either
    opponent_board = "NONE"; // ^
    ships = new Boat[maxShips];

    turn = false;
    name = "NONE";
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

Player::Player(const Player& rhs){
    numShips = rhs.numShips;
    maxShips = rhs.maxShips;

    player1_board = rhs.player1_board;
    opponent_board = rhs.opponent_board;
    ships = new Boat[maxShips];

    for (int i = 0; i < numShips; i++) {
        ships[i] = rhs.ships[i];
    }

    turn = rhs.turn;
    name = rhs.name;
}

Player::~Player(){
    delete[] ships;
}

Player& Player::operator=(const Player& rhs){
    numShips = rhs.numShips;
    maxShips = rhs.maxShips;

    player1_board = rhs.player1_board;
    opponent_board = rhs.opponent_board;
    ships = new Boat[maxShips];

    for (int i = 0; i < numShips; i++) {
        ships[i] = rhs.ships[i];
    }

    turn = rhs.turn;
    name = rhs.name;
    
    return *this;
}

string Player::getPlayer1_Board(){
    return player1_board;
}

string Player::getOpponent_Board(){
    return opponent_board;
}

Boat* Player::getShips(){
    return ships;
}

bool Player::getTurn(){
    return turn;
}

string Player::getName(){
    return name;
}

void Player::setPlayer1_Board(string pb){
    player1_board = pb;
}

void Player::setOpponent_Board(string op){
    opponent_board = op;
}

void Player::setTurn(bool t){
    turn = t;
}

void Player::setName(string nm){
    name = nm;   
}
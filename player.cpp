#include "player.h"

Player::Player() : playerBoard(), opponentBoard(), ships(), guesses() {
    turn = false;
    name = "NONE";
}

Player::Player(DynamicArray<int> pb, DynamicArray<int> ob, DynamicArray<Boat> sh, DynamicArray<int> g, bool t, string nm) : playerBoard(pb), opponentBoard(ob), ships(sh), guesses(g){
    turn = t;
    name = nm;
}

Player::Player(const Player& rhs){ //: playerBoard(rhs.playerBoard), opponentBoard(rhs.opponentBoard), ships(rhs.ships), guesses(rhs.guesses){
    playerBoard = rhs.playerBoard;
    opponentBoard = rhs.opponentBoard;
    ships = rhs.ships;
    guesses = rhs.guesses;
    
    turn = rhs.turn;
    name = rhs.name;
}

Player::~Player(){
    playerBoard.clearArray();
    opponentBoard.clearArray();
    ships.clearArray();
    guesses.clearArray();
}

Player& Player::operator=(const Player& rhs){
    playerBoard = rhs.playerBoard;
    opponentBoard = rhs.opponentBoard;
    ships = rhs.ships;
    guesses = rhs.guesses;
    
    turn = rhs.turn;
    name = rhs.name;
    return *this
}

DynamicArray<int>& Player::getPlayerBoard(){
    return playerBoard;
}

DynamicArray<int>& Player::getOpponentBoard(){
    return opponentBoard;
}

DynamicArray<Boat>& Player::getShips(){
    return ships;
}

DynamicArray<int>& Player::getGuesses(){
    return guesses;
}

bool Player::getTurn(){
    return turn;
}

string Player::getName(){
    return name;
}

void Player::setPlayerBoard(DynamicArray<int>& pb){
    playerBoard = pb;
}

void Player::setOpponentboard(DynamicArray<int>& ob){
    opponentBoard = ob;
}

void Player::setShips(DynamicArray<Boat>& sh){
    ships = sh;
}

void Player::setGuesses(DynamicArray<int>& g){
    guesses = g;
}

void Player::setTurn(bool t){
    turn = t;
}

void Player::setName(string nm){
    name = nm;   
}
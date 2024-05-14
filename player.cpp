#include "player.h"
#include "helpers.h"

Player::Player() : playerBoard(), opponentBoard(), ships(), guesses() {
    turn = false;
    name = "NONE";
}

Player::Player(DynamicArray<int> pb, DynamicArray<int> ob, DynamicArray<Boat> sh, DynamicArray<Square> g, bool t, string nm) : playerBoard(pb), opponentBoard(ob), ships(sh), guesses(g){
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
    return *this;
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

DynamicArray<Square>& Player::getGuesses(){
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

void Player::setGuesses(DynamicArray<Square>& g){
    guesses = g;
}

void Player::setTurn(bool t){
    turn = t;
}

void Player::setName(string nm){
    name = nm;   
}

void Player::takeTurn(Player p){
    //will change square to struct when we implement it
    bool guess, hit, sunk;

    do{
        displayBoards(p);
        cout << "Enter the square on your opponent's board you'd like to fire at: ";
        //get square, implement later
        //guess = checkGuess();
    }while(guess == false);
    //add to guesses array

    //hit = checkHit();

    if(hit == true){
        cout << "You hit the opponent's " << /*get name of ship <<*/ "! Hopefully it sinks soon." << endl;
        //check if ship was sunk
        if(sunk == true){
            cout << "Congratulations, you sunk the opponent's " << /*get name of ship <<*/ "!! Sucks to be them!" << endl;
            //show ascii art of firework or something if i wanna be extra? 
        }
    }else{
        cout << "You missed. You aren't very good at this, are you." << endl;
    }

}


bool Player::isSquareOccupied(const Square& s) const{
    return playerBoard.getArray()[convertSquaresToIndex(s)] != 0;
}

int Player::convertSquaresToIndex(const Square& s) const{
    return (s.row - 'A') * 10 + (s.col - 1);
}

void Player::occupuySquare(const Square& s){
    playerBoard.getArray()[convertSquaresToIndex(s)] = 1;
}

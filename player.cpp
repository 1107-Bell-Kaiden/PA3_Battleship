#include "player.h"
#include "helpers.h"

Player::Player() : playerBoard(), opponentBoard(), ships(), guesses() {
    turn = false;
    name = "NONE";
    playerBoard.fill(0); //fill the board with 0's
    opponentBoard.fill(0); //fill the opp board with 0's

    // Intialize Ships:
    ships.addItemToArray(Boat(Square(), Square(), "Carrier", 5));
    ships.addItemToArray(Boat(Square(), Square(), "Battleship", 4));
    ships.addItemToArray(Boat(Square(), Square(), "Destroyer", 3));
    ships.addItemToArray(Boat(Square(), Square(), "Submarine", 3));
    ships.addItemToArray(Boat(Square(), Square(), "Patrol Boat", 2));
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

Boat& Player::getBoat(int shipType){
    return ships.getArray()[shipType - 1];
}

string Player::getShipTypeName(int shipType){
    switch (shipType) {
        case 1: return "Carrier";
        case 2: return "Battleship";
        case 3: return "Destroyer";
        case 4: return "Submarine";
        case 5: return "Patrol Boat";
        default: return "Invalid ship type";
    }
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

void Player::takeTurn(Player& opponent){
    Square square;
    bool guess, hit, sunk;

    do{
        displayBoards(opponent);
        cout << "Enter the square on your opponent's board you'd like to fire at: ";
        cin >> square;
        guess = checkGuess(square, guesses); //check if guess if valid
    } while(!guess);

    guesses.addItemToArray(square);

    hit = checkHit(square, opponent);

    updateBoard(square, hit, opponentBoard); //update the opponent's board
    if(hit){
        markHit(square); 
        //Ship names:
        int shipType = opponent.getPlayerBoard().getArray()[convertSquaresToIndex(square)]; //get the ship type


        cout << "You hit the opponent's " << getShipTypeName(shipType) << "! Hopefully it sinks soon!" << endl;
        //check if ship is sunk
        Boat& hitOnBoat = opponent.getBoat(shipType);
        int posOnBoat = opponent.calcPosOnBoat(shipType, square);

        hitOnBoat.hit(posOnBoat);
        sunk = hitOnBoat.isSunk();

        if(sunk) {
            cout << "Congratulations, you sunk the opponent's " << getShipTypeName(shipType) << "!! Sucks to be them!" << endl;
        }

    } else{
        markMiss(square);
        cout << "You missed. You aren't very good at this, are you." << endl;
    }
}

int Player::calcPosOnBoat(int shipType, const Square& square){
    Boat& boat = getBoat(shipType);
    Square front = boat.getBoatFront();

    if (front.row == square.row) {
        return square.col - front.col;
    } else {
        return square.row - front.row;
    }
}

bool Player::isSquareOccupied(const Square& s) const{
    return playerBoard.getArray()[convertSquaresToIndex(s)] != 0;
}

int Player::convertSquaresToIndex(const Square& s) const{
    return (s.row - 'A') * 10 + (s.col - 1);
}
void Player::occupuySquare(const Square& s, int shipType){
    playerBoard.getArray()[convertSquaresToIndex(s)] = shipType;
}

void Player::markHit(const Square& s){
    playerBoard.getArray()[convertSquaresToIndex(s)] = 10;  
}

void Player::markMiss(const Square& s){
    playerBoard.getArray()[convertSquaresToIndex(s)] = 11;
}
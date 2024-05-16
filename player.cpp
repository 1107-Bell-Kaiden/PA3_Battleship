#include "player.h"
#include "aiPlayer.h"
#include "helpers.h"

Player::Player() : playerBoard(), opponentBoard(), ships(), guesses() {
    turn = false;
    name = "NONE";
    playerBoard.fill(0); //fill the board with 0's
    opponentBoard.fill(0); //fill the opp board with 0's

    // Intialize Ships:
    ships.addItemToArray(Boat(Square('A', 1), Square('A', 5), "Carrier", 5));
    ships.addItemToArray(Boat(Square('B', 1), Square('B', 4), "Battleship", 4));
    ships.addItemToArray(Boat(Square('C', 1), Square('C', 3), "Destroyer", 3));
    ships.addItemToArray(Boat(Square('D', 1), Square('D', 3), "Submarine", 3));
    ships.addItemToArray(Boat(Square('E', 1), Square('E', 2), "Patrol Boat", 2));
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

DynamicArray<int>& Player::getPlayerBoard() {
    return playerBoard;
}

const DynamicArray<int>& Player::getPlayerBoard() const{
    return playerBoard;
}

DynamicArray<int>& Player::getOpponentBoard() {
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

void Player::takeTurn(AiPlayer& opponent){
    Square square;
    bool guess, hit, sunk;

    do{
        displayPlayerBoard(*this); // Display Own Board
        cout << "--------------------" << endl;
        displayOpponentBoard(opponent); // Display Opponents board

        cout << "Enter the square on your opponent's board you'd like to fire at: ";
        cin >> square;
        guess = checkGuess(square, guesses); //check if guess if valid
        cout << endl;

    } while(!guess);

    guesses.addItemToArray(square);

    hit = checkHit(square, opponent);

    cout << "Shot at: " << square.row << square.col << (hit ? " hit" : " miss") << endl;

    if(hit){
        //Ship names:
        int shipType = opponent.getPlayerBoard().getArray()[convertSquaresToIndex(square)]; //get the ship type
        cout << "Detected ship type: " << shipType  << endl;

        markHit(square, opponent.getPlayerBoard());

        if (shipType >= 1 && shipType <= 5) {
            cout << "You hit the opponent's " << opponent.getShipTypeName(shipType) << "! Hopefully it sinks soon!" << endl;

            //check if ship is sunk
            Boat& hitOnBoat = opponent.getBoat(shipType);
            int posOnBoat = calcPosOnBoat(shipType, square);
            hitOnBoat.hit(posOnBoat);


            if(hitOnBoat.isSunk()){
                cout << "Congratulations, you sunk the opponent's " << opponent.getShipTypeName(shipType) << "!! Sucks to be them!" << endl;
            }
            
        } else {
            cout << "Error: Unexpected ship type val" << endl;
        }

    } else{
        markMiss(square, opponent.getPlayerBoard());
        cout << "You missed. You aren't very good at this, are you." << endl;
        cout << endl;
    }
    updateBoard(square, hit, opponent.getPlayerBoard());
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

void Player::markHit(const Square& s, DynamicArray<int>& board){
    board.getArray()[convertSquaresToIndex(s)] = 10;  
}

void Player::markMiss(const Square& s, DynamicArray<int>& board){
    board.getArray()[convertSquaresToIndex(s)] = 11;
}

bool Player::checkWin() const {
    for (int i = 0; i < ships.getCurrentSize(); i++) {
        const Boat& boat = ships.getElement(i);
        if(!boat.isSunk()) {
            return false;
        }
    }
    return true;
}
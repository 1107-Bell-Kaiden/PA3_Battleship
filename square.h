#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

struct Square{
    //properties
    char row;
    int col;
    
    //methods
    Square(){
        row = 'X';
        col = 0;
    }
    /*
    Square(char r, int c){
        row = r;
        col = c;
    }

    Square(const Square& rhs){
        row = rhs.row;
        col = rhs.col;
    }
    */
    Square& operator=(const Square& rhs){
        row = rhs.row;
        col = rhs.col;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Square& s){
        out << s.row << s.col;
        return out;
    }

    friend istream& operator>>(istream& in, Square& s){
        in >> s.row >> s.col;
        return in;
    }

};

#endif
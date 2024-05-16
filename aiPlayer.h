#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <time.h>
#include <stdlib.h>

#include "player.h"

class AiPlayer: public Player {
    
    public:
        void placeShipsRandom();
        void takeTurn(Player& opponent); 
        bool checkWin() const;

        DynamicArray<int>& getPlayerBoard();
};

#endif
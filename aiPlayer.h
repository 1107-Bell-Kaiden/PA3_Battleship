#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <time.h>
#include <stdlib.h>

#include "player.h"

class AiPlayer: public Player {
    
    public:
        void placeShipsRandom();
        void takeTurn(Player& opponent) override; // have to overload not override becuase of parameters?
};

#endif
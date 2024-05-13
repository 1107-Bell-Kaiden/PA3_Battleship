#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"
#include <time.h>
#include <stdlib.h>

//in the doc ig we had aiplayer inheriting from player, so it would be super short

class AiPlayer : public Player{

    public:
        void placeShipsRandom();
        void takeTurn(AiPlayer); // have to overload not override becuase of parameters?
};

#endif
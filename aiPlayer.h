#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"

//in the doc ig we had aiplayer inheriting from player, so it would be super short

class AiPlayer : public Player{
    public:
        void placeShipsRandom();
        //void takeTurn();
};

#endif
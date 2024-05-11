#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"

//in the doc ig we had aiplayer inheriting from player, so it would be super short

class AiPlayer : public Player{
    public:
        AiPlayer();
        AiPlayer(string, string, Boat*, bool, string, int, int) : Player();
        AiPlayer(const AiPlayer&):Player();


        void placeShipsRandom();
        void takeTurn() override; // <- if we use this then we have to override it here no?
};

#endif
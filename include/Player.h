#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class player : public Entity
{
public:
    bool thrust;
    player();
    void update() override;
};

#endif



// This file defines the Player class, which is a type of Entity. It adds properties and behavior specific to the player-controlled spaceship:

// thrust → a boolean to check whether the player is pressing the thrust key.

// The header declares the constructor and an update() function that moves the spaceship and handles speed/physics.
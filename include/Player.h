#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
    bool thrust;
    
    // Power-up properties
    bool hasShield;
    float shieldTimer;
    float speedBoostTimer;
    float normalSpeed;
    float boostedSpeed;

    Player();
    void update() override;
    
    // Power-up methods
    void activateSpeedBoost();
    void addLife(int& lives);
    void activateShield();
    void updatePowerUps();
};

#endif



// This file defines the Player class, which is a type of Entity. It adds properties and behavior specific to the player-controlled spaceship:

// thrust → a boolean to check whether the player is pressing the thrust key.

//ZAINAB

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
    bool thrust;
    
    // power-up properties
    bool hasShield;
    float shieldTimer;
    float speedBoostTimer;
    float normalSpeed;
    float boostedSpeed;

    Player();
    void update() override;
    
    // power-up methods
    void activateSpeedBoost();
    void addLife(int& lives);
    void activateShield();
    void updatePowerUps();
};

#endif
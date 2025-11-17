// #ifndef PLAYER_H
// #define PLAYER_H

// #include "Entity.h"

// class Player : public Entity
// {
// public:
//     bool thrust;
//     Player();
//     void update() override;
//     // add these members inside player class (public or protected as per your style)
//     int lives = 3;                // player's health / lives
//     bool shieldActive = false;    // paratha effect
//     float shieldTimer = 0.0f;

//     float speedMultiplier = 1.0f; // chai effect
//     float speedTimer = 0.0f;

//     // declarations (place with other methods)
//     void activateShield(float seconds);
//     void activateSpeed(float seconds);
//     void restoreHealth(int amount);
//     void updatePowerups(float dt);

// };

// #endif



// // This file defines the Player class, which is a type of Entity. It adds properties and behavior specific to the player-controlled spaceship:

// // thrust → a boolean to check whether the player is pressing the thrust key.

// // The header declares the constructor and an update() function that moves the spaceship and handles speed/physics.



// #ifndef PLAYER_H
// #define PLAYER_H

// #include "Entity.h"
// #include <SFML/Graphics.hpp>

// class Player : public Entity {
// public:
//     float dx, dy;
//     int health;
//     bool isProtected;
//     float protectionTimer;
//     float speed;
//     float speedTimer;

//     Player();
//     void update() override;

//     // Power-up effects
//     void speedBoost();
//     void heal();
//     void activateShield();
// };

// #endif



#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity {
public:
    float dx, dy;
    int health;
    bool isProtected;
    float protectionTimer;
    float speed;
    float speedTimer;

    Player();
    void update() override;

    // Power-up effects
    void speedBoost();
    void heal();
    void activateShield();
};

#endif


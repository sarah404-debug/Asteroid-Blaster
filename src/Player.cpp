// #include "Player.h"
// #include <cmath>
// #include "Globals.h"



// Player::Player()
// {
//     name = "player";
// }



// void Player::activateShield(float seconds) {
//     shieldActive = true;
//     shieldTimer = seconds;
// }

// void Player::activateSpeed(float seconds) {
//     speedMultiplier = 1.7f; // example boost
//     speedTimer = seconds;
// }

// void Player::restoreHealth(int amount) {
//     lives += amount;
//     // optionally cap lives, e.g. if (lives>5) lives=5;
// }

// void Player::updatePowerups(float dt) {
//     if (shieldActive) {
//         shieldTimer -= dt;
//         if (shieldTimer <= 0.0f) {
//             shieldActive = false;
//             shieldTimer = 0;
//         }
//     }
//     if (speedTimer > 0.0f) {
//         speedTimer -= dt;
//         if (speedTimer <= 0.0f) {
//             speedMultiplier = 1.0f;
//             speedTimer = 0;
//         }
//     }
// }

// void Player::update()
// {
//     if (thrust)
//     {
//         dx += cos(angle * DEGTORAD) * 0.2;
//         dy += sin(angle * DEGTORAD) * 0.2;
//     }
//     else
//     {
//         dx *= 0.99;
//         dy *= 0.99;
//     }

//     int maxSpeed = 15;
//     float speed = sqrt(dx * dx + dy * dy);
//     if (speed > maxSpeed)
//     {
//         dx *= maxSpeed / speed;
//         dy *= maxSpeed / speed;
//     }

//     x += dx;
//     y += dy;

//     if (x > W)
//         x = 0;
//     if (x < 0)
//         x = W;
//     if (y > H)
//         y = 0;
//     if (y < 0)
//         y = H;

//     if (thrust) {
//     dx += cos(angle * DEGTORAD) * 0.2f * speedMultiplier;
//     dy += sin(angle * DEGTORAD) * 0.2f * speedMultiplier;
//     }

// }



// // This file explains how the player moves:
// // Constructor (player())
// // Sets the entity’s name to "player" so the game can identify it.
// // update() function
// // If thrust is true, the player accelerates in the direction of angle using cos and sin.
// // If thrust is false, the player slows down gradually (dx and dy are multiplied by 0.99).
// // maxSpeed ensures the player cannot move too fast. The current speed is calculated using the Pythagorean theorem: sqrt(dx*dx + dy*dy). If speed exceeds maxSpeed, it scales dx and dy proportionally.
// // Updates the player’s position (x and y) based on dx and dy.
// // Wraps the player around the screen: if the player moves off one edge, they appear on the opposite side (W = width, H = height).
// // In short, this class controls how the player spaceship accelerates, moves, slows down, and wraps around the screen.


#include "Player.h"
#include "Globals.h"
#include <cmath>

Player::Player()
{
    name = "player";
    thrust = false;
}

void Player::update()
{
    if (thrust)
    {
        dx += cos(angle * DEGTORAD) * 0.2;
        dy += sin(angle * DEGTORAD) * 0.2;
    }
    else
    {
        dx *= 0.99;
        dy *= 0.99;
    }

    int maxSpeed = 15;
    float speed = sqrt(dx*dx + dy*dy);

    if (speed > maxSpeed)
    {
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx;
    y += dy;

    if (x > W) x = 0;
    if (x < 0) x = W;
    if (y > H) y = 0;
    if (y < 0) y = H;
}

// // This file explains how the player moves:
// // Constructor (player())
// // Sets the entity’s name to "player" so the game can identify it.
// // update() function
// // If thrust is true, the player accelerates in the direction of angle using cos and sin.
// // If thrust is false, the player slows down gradually (dx and dy are multiplied by 0.99).
// // maxSpeed ensures the player cannot move too fast. The current speed is calculated using the Pythagorean theorem: sqrt(dx*dx + dy*dy). If speed exceeds maxSpeed, it scales dx and dy proportionally.
// // Updates the player’s position (x and y) based on dx and dy.
// // Wraps the player around the screen: if the player moves off one edge, they appear on the opposite side (W = width, H = height).
// // In short, this class controls how the player spaceship accelerates, moves, slows down, and wraps around the screen.

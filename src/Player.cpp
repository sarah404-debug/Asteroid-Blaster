#include "Player.h"
#include "Globals.h"
#include <cmath>

Player::Player()
{
    name = "player";
    thrust = false;

    // Power-up defaults
    hasShield = false;
    shieldTimer = 0;
    speedBoostTimer = 0;
    normalSpeed = 0.1f;       // base movement speed
    boostedSpeed = 0.2f;      // speed when boost is active
}

void Player::update()
{
    updatePowerUps();         // decrease timers

    float currentSpeed = (speedBoostTimer > 0) ? boostedSpeed : normalSpeed;

    if (thrust)               // accelerate forward
    {
        dx += cos(angle * DEGTORAD) * currentSpeed;
        dy += sin(angle * DEGTORAD) * currentSpeed;
    }
    else                      // slow down gradually
    {
        dx *= 0.99;
        dy *= 0.99;
    }

    int maxSpeed = (speedBoostTimer > 0) ? 20 : 15;  // higher cap during boost
    float speed = sqrt(dx*dx + dy*dy);

    if (speed > maxSpeed)     // clamp velocity
    {
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx;                  // update position
    y += dy;

    // wrap around screen edges
    if (x > W) x = 0;
    if (x < 0) x = W;
    if (y > H) y = 0;
    if (y < 0) y = H;
}

void Player::activateSpeedBoost()
{
    speedBoostTimer = 300;    // ~5 seconds
}

void Player::addLife(int& lives)
{
    if (lives < 5)            // cap at 5
        lives++;
}

void Player::activateShield()
{
    hasShield = true;
    shieldTimer = 360;        // ~6 seconds
}

void Player::updatePowerUps()
{
    if (speedBoostTimer > 0)
        speedBoostTimer--;    // tick boost timer

    if (shieldTimer > 0)      // tick shield timer
    {
        shieldTimer--;
        if (shieldTimer <= 0)
            hasShield = false; // disable shield
    }
}
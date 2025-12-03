#include "Player.h"
#include "Globals.h"
#include <cmath>

Player::Player()
{
    name = "player";
    thrust = false;
    
    // Power-up initialization
    hasShield = false;
    shieldTimer = 0;
    speedBoostTimer = 0;
    normalSpeed = 0.1f;   // was 0.2
    boostedSpeed = 0.2f;  // was 0.4

}

void Player::update()
{
    // Update power-up timers
    updatePowerUps();
    
    float currentSpeed = (speedBoostTimer > 0) ? boostedSpeed : normalSpeed;
    
    if (thrust)
    {
        dx += cos(angle * DEGTORAD) * currentSpeed;
        dy += sin(angle * DEGTORAD) * currentSpeed;
    }
    else
    {
        dx *= 0.99;
        dy *= 0.99;
    }

    int maxSpeed = (speedBoostTimer > 0) ? 20 : 15;
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

void Player::activateSpeedBoost()
{
    speedBoostTimer = 300; // 5 seconds at 60 FPS
}

void Player::addLife(int& lives)
{
    if (lives < 5) // Max 5 lives
        lives++;
}

void Player::activateShield()
{
    hasShield = true;
    shieldTimer = 360; // 6 seconds at 60 FPS
}

void Player::updatePowerUps()
{
    // Update speed boost timer
    if (speedBoostTimer > 0)
        speedBoostTimer--;
    
    // Update shield timer
    if (shieldTimer > 0)
    {
        shieldTimer--;
        if (shieldTimer <= 0)
            hasShield = false;
    }
}
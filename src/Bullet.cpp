#include "Bullet.h"
#include "Globals.h"
#include <cmath>

Bullet::Bullet()
{
    name = "bullet";
}

void Bullet::update()
{
    dx = cos(angle * DEGTORAD) * 6;
    dy = sin(angle * DEGTORAD) * 6;

    x += dx;
    y += dy;

    if (x > W || x < 0 || y > H || y < 0)
        life = false;
}


//This file explains how bullets behave.

// When a bullet is created, it is given the name "bullet" so the game can identify it.

// In the update() function:

// dx and dy are calculated using the bullet’s angle so it moves in the direction the player is pointing.

// The bullet’s position (x and y) is updated each frame to make it move smoothly.

// If the bullet goes off the screen edges (W and H), it is marked as dead (life = 0) so the game can remove it.

// In short, this file makes bullets fly in the correct direction and disappear when they leave the screen

#include "Bullet.h"
#include "Globals.h"
#include <cmath>

Bullet::Bullet()
{
    name = "bullet";   // Set object name
}

void Bullet::update()
{
    dx = cos(angle * DEGTORAD) * 6;   // horizontal velocity based on angle
    dy = sin(angle * DEGTORAD) * 6;   //vertical velocity based on angle

    x += dx;   // moe bullet on x-axis
    y += dy;   // move bullet on y-axis

    // bullet leaves screen bounds, destroy 
    if (x > W || x < 0 || y > H || y < 0)
        life = false;
}

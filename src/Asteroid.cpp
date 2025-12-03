#include "Asteroid.h"
#include "Globals.h"
#include <cstdlib>

Asteroid::Asteroid()
{
    dx = rand() % 4 - 2;
    dy = rand() % 4 - 2;
    name = "asteroid";
}

void Asteroid::update()
{
    x += dx;
    y += dy;

    if (x > W) x = 0;
    if (x < 0) x = W;
    if (y > H) y = 0;
    if (y < 0) y = H;
}


//This file explains how the asteroid behaves.
//When an asteroid is created, it’s given a random speed and direction (dx and dy) so every asteroid moves differently. 
//In the update() function, the asteroid’s position (x and y) changes each frame, making it move around the screen. 
//If it goes off one edge, it appears back on the opposite side — this makes the asteroid movement continuous and natural, as if space loops around.

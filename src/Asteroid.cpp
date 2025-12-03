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


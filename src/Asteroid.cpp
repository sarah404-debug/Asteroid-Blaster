#include "Asteroid.h"
#include "Globals.h"
#include <cstdlib>

// Constructor: Initialize asteroid with random velocity
Asteroid::Asteroid()
{
    dx = rand() % 4 - 2;  // Random horizontal speed (-2 to 1)
    dy = rand() % 4 - 2;  // Random vertical speed (-2 to 1)
    name = "asteroid";
}

// Update asteroid position each frame
void Asteroid::update()
{
    // Move asteroid based on velocity
    x += dx;
    y += dy;

    // Wrap around screen edges (teleport to opposite side)
    if (x > W) x = 0;      // Right edge -> Left side
    if (x < 0) x = W;      // Left edge -> Right side
    if (y > H) y = 0;      // Bottom edge -> Top side
    if (y < 0) y = H;      // Top edge -> Bottom side
}

#include "PowerUp.h"
#include "Globals.h"
#include <cstdlib>

PowerUp::PowerUp(PowerUpType t, sf::Texture* tex) : type(t)
{
    name = "powerup";
    life = true;
    sprite.setTexture(*tex);
    
    // Set origin to center of sprite
    sf::Vector2u texSize = tex->getSize();
    sprite.setOrigin(texSize.x / 2.0f, texSize.y / 2.0f);
    sprite.setScale(0.2f, 0.2f); // Scale down - adjust as needed
    //sprite.setScale(0.3f, 0.3f); // Make them MUCH bigger temporarily
    
    // Random slow movement
    dx = (rand() % 3 - 1) * 0.5f;
    dy = (rand() % 3 - 1) * 0.5f;
}

void PowerUp::update()
{
    x += dx;
    y += dy;
    
    // Wrap around screen
    if (x > W) x = 0;
    if (x < 0) x = W;
    if (y > H) y = 0;
    if (y < 0) y = H;
}

void PowerUp::draw(sf::RenderWindow& app)
{
    sprite.setPosition(x, y);
    app.draw(sprite);
    
    
}
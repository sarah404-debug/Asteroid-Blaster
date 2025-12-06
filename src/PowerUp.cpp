#include "PowerUp.h"
#include "Globals.h"
#include <cstdlib>

PowerUp::PowerUp(PowerUpType t, sf::Texture* tex) : type(t)
{
    name = "powerup";
    life = true;
    sprite.setTexture(*tex);

    // cnter the sprite
    sf::Vector2u texSize = tex->getSize();
    sprite.setOrigin(texSize.x / 2.0f, texSize.y / 2.0f);
    sprite.setScale(0.2f, 0.2f); // resize sprite

    // give slow random drifting movement
    dx = (rand() % 3 - 1) * 0.5f;
    dy = (rand() % 3 - 1) * 0.5f;
}

void PowerUp::update()
{
    x += dx;   // move horizontally
    y += dy;   // move vertically

    // wrap around edges
    if (x > W) x = 0;
    if (x < 0) x = W;
    if (y > H) y = 0;
    if (y < 0) y = H;
}

void PowerUp::draw(sf::RenderWindow& app)
{
    sprite.setPosition(x, y); // update sprite position
    app.draw(sprite);         // render to window
}

#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

enum class PowerUpType { CHAI, PAKOLA, PARATHA };

class PowerUp : public Entity
{
public:
    PowerUpType type;
    sf::Sprite sprite;

    
    PowerUp(PowerUpType t, sf::Texture* tex);

    void update() override;
    void draw(sf::RenderWindow& app) override;  // No override
};

#endif
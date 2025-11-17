// #ifndef POWERUP_H
// #define POWERUP_H

// #include "Entity.h"
// #include <string>

// enum class PowerUpType { CHAI, PAKOLA, PARATHA };

// class PowerUp : public Entity
// {
// public:
//     PowerUpType type;
//     float duration;    // effect duration in seconds
//     float lifeTimer;   // how long the powerup exists in world before disappearing

//     PowerUp(PowerUpType t);
//     PowerUp(const std::string &name);
//     void update() override;
// };

// #endif
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
    void draw(sf::RenderWindow& app) override;
};

#endif

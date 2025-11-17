// // #include "PowerUp.h"
// // #include "Globals.h"
// // #include <cstdlib>

// // PowerUp::PowerUp(PowerUpType t)
// // {
// //     type = t;
// //     name = "powerup";
// //     duration = 6.0f;    // default effect lasts 6 seconds
// //     lifeTimer = 12.0f;  // powerup exists 12 seconds in world
// //     dx = (std::rand()%100 - 50) / 100.0f; // slow drift
// //     dy = (std::rand()%100 - 50) / 100.0f;
// // }

// // PowerUp::PowerUp(const std::string &nm) 
// // {
// //     name = "powerup";
// //     lifeTimer = 12.0f;
// //     dx = (std::rand()%100 - 50) / 100.0f;
// //     dy = (std::rand()%100 - 50) / 100.0f;

// //     if (nm == "chai.png" || nm == "chai") type = PowerUpType::CHAI;
// //     else if (nm == "pakola.jpg" || nm == "pakola") type = PowerUpType::PAKOLA;
// //     else type = PowerUpType::PARATHA;
// // }

// // void PowerUp::update()
// // {
// //     // drift
// //     x += dx;
// //     y += dy;

// //     // wrap
// //     if (x > W) x = 0; if (x < 0) x = W;
// //     if (y > H) y = 0; if (y < 0) y = H;

// //     // animation advance if any
// //     anim.update();

// //     // lifetime countdown
// //     lifeTimer -= 1.0f/60.0f; // assuming update() called at ~60 FPS; otherwise use dt variant
// //     if (lifeTimer <= 0) life = false;
// // }
// #include "PowerUp.h"
// #include "Globals.h"
// #include <cstdlib>

// PowerUp::PowerUp(PowerUpType t)
// {
//     type = t;
//     name = "powerup";
//     duration = 6.0f;
//     lifeTimer = 12.0f;
//     dx = (std::rand()%100 - 50) / 100.0f;
//     dy = (std::rand()%100 - 50) / 100.0f;
// }

// PowerUp::PowerUp(const std::string &nm) 
// {
//     name = "powerup";
//     lifeTimer = 12.0f;
//     dx = (std::rand()%100 - 50) / 100.0f;
//     dy = (std::rand()%100 - 50) / 100.0f;

//     if (nm == "chai.png" || nm == "chai") type = PowerUpType::CHAI;
//     else if (nm == "pakola.jpg" || nm == "pakola") type = PowerUpType::PAKOLA;
//     else type = PowerUpType::PARATHA;
// }

// void PowerUp::update()
// {
//     x += dx; y += dy;
//     if (x > W) x = 0; if (x < 0) x = W;
//     if (y > H) y = 0; if (y < 0) y = H;

//     anim.update();
//     lifeTimer -= 1.0f/60.0f;
//     if (lifeTimer <= 0) life = false;
// }
#include "PowerUp.h"

PowerUp::PowerUp(PowerUpType t, sf::Texture* tex)
{
    type = t;
    name = "powerup";
    life = true;

    sprite.setTexture(*tex);
    sprite.setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
    R = 20; // radius for collision
}

void PowerUp::update()
{
    // Slow rotation for effect
    sprite.rotate(1.0f);
}

void PowerUp::draw(sf::RenderWindow& app)
{
    sprite.setPosition(x, y);
    app.draw(sprite);
}

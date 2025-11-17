// #include "Entity.h"
// #include "Globals.h"

// Entity::Entity()
// {
//     life = true;
// }

// Entity::~Entity() {}

// void Entity::settings(Animation &a, int X, int Y, float Angle, int radius)
// {
//     anim = a;
//     x = X;
//     y = Y;
//     angle = Angle;
//     R = radius;
// }

// void Entity::update() {}

// void Entity::draw(sf::RenderWindow &app)
// {
//     anim.sprite.setPosition(x, y);
//     anim.sprite.setRotation(angle + 90);
//     app.draw(anim.sprite);

//     sf::CircleShape circle(R);
//     circle.setFillColor(sf::Color(255, 0, 0, 170));
//     circle.setPosition(x, y);
//     circle.setOrigin(R, R);
//     // app.draw(circle);
// }

// bool isCollide(Entity *a, Entity *b)
// {
//     return (b->x - a->x) * (b->x - a->x) +
//                (b->y - a->y) * (b->y - a->y) <
//            (a->R + b->R) * (a->R + b->R);
// }

#include "Entity.h"
#include "Globals.h"

Entity::Entity() { life = true; }
Entity::~Entity() {}

void Entity::settings(const Animation &a, int X, int Y, float Angle, int radius)
{
    anim = a;
    x = X;
    y = Y;
    angle = Angle;
    R = radius;
}

void Entity::update() {}

void Entity::draw(sf::RenderWindow &app)
{
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation(angle + 90);
    app.draw(anim.sprite);
}

bool isCollide(Entity *a, Entity *b)
{
    return (b->x - a->x)*(b->x - a->x) + (b->y - a->y)*(b->y - a->y) < (a->R + b->R)*(a->R + b->R);
}




// This file defines how these functions work:
// Entity() → sets life = true when the entity is created
// settings() → assigns the animation, position, angle, and radius to the entity
// update() → empty here, meant to be overridden by child classes like Player or Bullet
// draw() → positions and rotates the sprite on screen; it can also optionally draw a red collision circle for debugging
// isCollide() → uses the circle collision formula to check if two entities overlap
// In short, the Entity class is a general template for all objects in the game, giving them basic movement, drawing, and collision features that other classes inherit and extend.
#include "Entity.h"
#include "Globals.h"

Entity::Entity() { life = true; }   // alive by default
Entity::~Entity() {}

void Entity::settings(const Animation &a, int X, int Y, float Angle, int radius)
{
    anim = a;        // animation to use
    x = X;           // position x
    y = Y;           // position y
    angle = Angle;   // rotation angle
    R = radius;      // collision radius
}

void Entity::update() {}            // base update

void Entity::draw(sf::RenderWindow &app)
{
    anim.sprite.setPosition(x, y);      // place sprite
    anim.sprite.setRotation(angle + 90); // adjust rotation
    app.draw(anim.sprite);              // render sprite
}

bool isCollide(Entity *a, Entity *b)
{
    // check circle overlap
    return (b->x - a->x)*(b->x - a->x) + 
           (b->y - a->y)*(b->y - a->y) < 
           (a->R + b->R)*(a->R + b->R);
}

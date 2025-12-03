
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.h"

class Entity
{
public:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name;
    Animation anim;

    Entity();
    virtual ~Entity();

    void settings(const Animation &a, int X, int Y, float Angle = 0, int radius = 1);
    virtual void update();
    virtual void draw(sf::RenderWindow &app);
};

bool isCollide(Entity *a, Entity *b);

#endif



// This file defines the Entity class, which is the base class for all objects in the game, like the player, asteroids, and bullets. It declares common properties that all entities share, such as:
// x, y → position
// dx, dy → movement speed in x and y directions
// R → radius for collision detection
// angle → direction of rotation
// life → whether the entity is alive
// name → identifier for the type of entity
// Animation anim → animation for the entity
// It also declares functions:
// settings() → initializes the entity’s position, animation, and radius
// update() → updates the entity each frame (can be customized in child classes)
// draw() → draws the entity on the screen
// isCollide() → checks if two entities are colliding
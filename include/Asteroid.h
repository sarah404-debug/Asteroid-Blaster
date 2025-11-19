

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
    Asteroid();
    void update() override;
};

#endif


//This file creates the Asteroid class, which is a special type of Entity. 
//It tells the program that every asteroid in the game will have its own movement and behavior. 
//The header just declares what the class can do — for example, it says that asteroids will have an update() function that will be defined later.

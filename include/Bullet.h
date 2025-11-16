#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class bullet : public Entity
{
public:
    bullet();
    void update() override;
};

#endif


//This file defines the Bullet class, which is a type of Entity. 
//It tells the program that bullets exist in the game and have their own behavior. 
//The header declares that bullets have a constructor and an update() function, which will control their movement on the screen.

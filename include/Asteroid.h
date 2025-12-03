/// HUZAIFA

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


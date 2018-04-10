#pragma once
#include "Particle.h"

class IStrategy
{
private:
public:
    virtual void change(Particle& drawable, float elapsedTime);
};
#pragma once
#include "Particle.h"

class IBehaviour
{
public:
    IBehaviour() { };
    virtual void lerp(Particle& particle) {};
};
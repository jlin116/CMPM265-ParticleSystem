#include "IBehaviour_DecreaseVelocity.h"
#include <iostream>

void IBehaviour_DecreaseVelocity::lerp(Particle& particle)
{
    particle.m_velocity *= 0.995f;
}

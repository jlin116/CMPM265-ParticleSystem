#include "IBehaviour_IncreaseVelocity.h"

void IBehaviour_IncreaseVelocity::lerp(Particle& particle)
{
    particle.m_velocity *= 1.001f;
}
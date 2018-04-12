#include "IBehaviour_DecreaseSize.h"

IBehaviour_DecreaseSize::IBehaviour_DecreaseSize()
{
    m_minSize = Vector2f(0, 0);
}

void IBehaviour_DecreaseSize::lerp(Particle& particle)
{
    super::lerp(particle);

    Vector2f particleSize = particle.getSize();
    float timeFrac = (particle.m_duration - m_timeFrac) / particle.m_duration;

    particle.setScale(Vector2f(timeFrac, timeFrac));
}

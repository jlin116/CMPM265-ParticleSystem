#include "IBehaviour_IncreaseSize.h"

IBehaviour_IncreaseSize::IBehaviour_IncreaseSize(Vector2f maxSize)
{
    m_maxSize = maxSize;
}

void IBehaviour_IncreaseSize::lerp(Particle& particle)
{
    Vector2f particleSize = particle.getSize();
    float timeFrac = (particle.m_duration - particle.m_lifespan) / particle.m_duration;
    Vector2f scaleRatio = Vector2f(m_maxSize.x / particleSize.x, m_maxSize.y / particleSize.y);

    particle.setScale(timeFrac * scaleRatio);
}

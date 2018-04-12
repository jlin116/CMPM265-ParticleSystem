#include "IBehaviour_IncreaseSize.h"

IBehaviour_IncreaseSize::IBehaviour_IncreaseSize(Vector2f maxSize)
{
    m_maxSize = maxSize;
}

void IBehaviour_IncreaseSize::lerp(Particle& particle)
{
    super::lerp(particle);

    Vector2f particleSize = particle.getSize();
    Vector2f scaleRatio = Vector2f(m_maxSize.x / particleSize.x, m_maxSize.y / particleSize.y);

    particle.setScale(m_timeFrac * scaleRatio);
}

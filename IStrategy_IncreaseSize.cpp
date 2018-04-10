#include "IStrategy_IncreaseSize.h"

#define TARGET_SIZE 10

void IStrategy_IncreaseSize::change(Particle& particle, float elapsedTime)
{
    Vector2f currentSize = particle.getSize();
    if (currentSize == Vector2f(TARGET_SIZE, TARGET_SIZE))
        return;

    float updateSize = (particle.m_defaultLifespan - particle.m_lifespan) / particle.m_defaultLifespan * TARGET_SIZE;
}

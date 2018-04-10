#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int count) :
    m_particles(count),
    m_vertices(Points, count),
    m_lifetime(seconds(3)),
    m_emitter(0, 0)
{

}

void ParticleSystem::setEmitter(Vector2f position)
{
    m_emitter = position;
}

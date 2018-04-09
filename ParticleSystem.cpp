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

void ParticleSystem::update(Time elapsed)
{
    for (std::size_t i = 0; i < m_particles.size() ++i)
    {

    }
}

void resetParticle(std::size_t index)
{
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    m_particles[index].velocity = Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

}


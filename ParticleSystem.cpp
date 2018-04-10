#include "ParticleSystem.h"
#include <iostream>

#define MAX_SPAWN_COUNT 10

ParticleSystem::ParticleSystem(Vector2f pos, unsigned int count)
{
    m_emitLocation = pos;
    m_particles = vector<Particle*>();
    m_particleCount = count;

    // fill the particle array with particles
    fillParticleSystem();
}

void ParticleSystem::update(float elapsedTime)
{
    // Fill the particle array
    fillParticleSystem();

    for (vector<Particle*>::iterator it = m_particles.begin(); it != m_particles.end();)
    {
        (*it)->update(elapsedTime);

        // Check the particle lifespan, return false means to be removed
        if (!(*it)->checkLifespan())
        {
            Particle *particle = *it;
            it = m_particles.erase(it);
            delete particle;
            continue;
        }

        ++it;
    }
}

void ParticleSystem::draw(RenderWindow& window)
{
    for (vector<Particle*>::iterator it = m_particles.begin(); it != m_particles.end(); ++it)
    {
        if ((*it) != nullptr)
        {
            window.draw(*(*it));
        }
    }
}

void ParticleSystem::fillParticleSystem()
{
    // Every frame will generate small amount instead of generating
    int spawnCount = (m_particleCount - m_particles.size() > MAX_SPAWN_COUNT) ? MAX_SPAWN_COUNT : (m_particleCount - m_particles.size());
    for (size_t i = 0; i < spawnCount; ++i)
    {
        m_particles.push_back(new Particle(m_emitLocation));
    }
}


#include "ParticleSystem.h"
#include <iostream>

#define MAX_SPAWN_COUNT 500
#define DEFAULT_SPAWN_COUNT 5
#define SPAWN_COUNT_INCREMENT 30

ParticleSystem::ParticleSystem(Vector2f pos, unsigned int count)
{
    m_emitLocation = pos;
    m_particles = vector<Particle*>();
    m_particleCount = count;

    // fill the particle array with particles
    fillParticleSystem();

    // Generate random particle emission angle and color
    m_startAngle = (float)(rand() % 360);
    m_emissionColor = Color(rand() % 255, rand() % 255, rand() % 255, 255);
    m_spawnControl = DEFAULT_SPAWN_COUNT;
    m_strategy = IStrategy();
}

void ParticleSystem::update(float elapsedTime)
{
    // Fill the particle array
    fillParticleSystem();

    for (vector<Particle*>::iterator it = m_particles.begin(); it != m_particles.end();)
    {
        // Apply strategy to particles
        m_strategy.change(**it, elapsedTime);
        // Update particle system state
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

void ParticleSystem::setStrategy(IStrategy strategy)
{
    m_strategy = strategy;
}

void ParticleSystem::changeParticleCount(unsigned int count)
{
    m_particleCount = count;
}

void ParticleSystem::fillParticleSystem()
{
    if (m_particles.size() >= m_particleCount)
        return;

    // Every frame will generate small amount instead of generating
    int spawnCount = (m_particleCount - (int)m_particles.size() > m_spawnControl) ? m_spawnControl : (m_particleCount - m_particles.size());
    for (size_t i = 0; i < spawnCount; ++i)
    {
        m_particles.push_back(new Particle(m_emitLocation, m_startAngle, m_emissionColor));
    }

    // Slowly ramping up the spawn amount
    m_spawnControl += SPAWN_COUNT_INCREMENT;
    if (m_spawnControl > MAX_SPAWN_COUNT)
        m_spawnControl = MAX_SPAWN_COUNT;
}


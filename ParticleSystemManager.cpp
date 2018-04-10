#include "ParticleSystemManager.h"

#define DEFAULT_PARTICLE_AMOUNT 2000

ParticleSystemManager::ParticleSystemManager()
{
    m_particleSystems = vector<ParticleSystem>();
    m_particleAmount = DEFAULT_PARTICLE_AMOUNT;

    font.loadFromFile("arial.ttf");
    uiText = Text("Particle Amount: ", font);
    uiText.setCharacterSize(32);
    uiText.setFillColor(Color::White);
}

void ParticleSystemManager::spawnParticleSystem(Vector2f pos, ParticleSystemManager::ParticleSystemMode mode)
{
    m_particleSystems.push_back(ParticleSystem(pos, m_particleAmount));
}

void ParticleSystemManager::increaseParticleAmount(unsigned int amount)
{
    m_particleAmount += amount;

    updateParticleAmount();
}

void ParticleSystemManager::decreaseParticleAmount(unsigned int amount)
{
    if (amount > m_particleAmount)
    {
        m_particleAmount = 0;
    }
    else
    {
        m_particleAmount -= amount;
    }

    updateParticleAmount();
}

void ParticleSystemManager::updateParticleAmount()
{
    for (vector<ParticleSystem>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it).changeParticleCount(m_particleAmount);
    }
}

void ParticleSystemManager::update(float elapsedTime)
{
    for (vector<ParticleSystem>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it).update(elapsedTime);
    }

    uiText.setString("Current Amount: " + to_string(m_particleAmount));
}

void ParticleSystemManager::draw(RenderWindow& window)
{
    for (vector<ParticleSystem>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it).draw(window);
    }

    window.draw(uiText);
}

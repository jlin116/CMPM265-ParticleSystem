#include "ParticleSystemManager.h"

#include "IBehaviour_IncreaseSize.h"

#define DEFAULT_PARTICLE_AMOUNT 50

ParticleSystemManager::ParticleSystemManager()
{
    m_particleSystems = vector<ParticleSystem*>();
    m_particleAmount = DEFAULT_PARTICLE_AMOUNT;

    font.loadFromFile("arial.ttf");
    uiText = Text("Particle Amount: ", font);
    uiText.setCharacterSize(16);
    uiText.setFillColor(Color::White);
}

ParticleSystemManager::~ParticleSystemManager()
{
    for (vector<ParticleSystem*>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end();)
    {
        delete *it;
        it = m_particleSystems.erase(it);
    }
}

void ParticleSystemManager::spawnParticleSystem(Vector2f pos, ParticleSystemManager::ParticleSystemMode mode)
{
    ParticleSystem* newParticleSystem = new ParticleSystem(pos, m_particleAmount);
    m_particleSystems.push_back(newParticleSystem);

    switch (mode)
    {
    case ParticleSystemMode::INCREASE_SIZE:
    {
        IBehaviour* newBehaviour = new IBehaviour_IncreaseSize(Vector2f(5, 5));
        newParticleSystem->setBehaviour(newBehaviour);
        break;
    }
    case ParticleSystemMode::SHRINK_SIZE:
    {

        break;
    }
    case ParticleSystemMode::INCREASE_VELOCITY:
    {

        break;
    }
    case ParticleSystemMode::DECREASE_VELOCITY:
    {

        break;
    }
    default:
        break;
    }
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
    for (vector<ParticleSystem*>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it)->changeParticleCount(m_particleAmount);
    }
}

void ParticleSystemManager::update(float elapsedTime)
{
    for (vector<ParticleSystem*>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it)->update(elapsedTime);
    }

    uiText.setString("Current Amount: " + to_string(m_particleAmount));
}

void ParticleSystemManager::draw(RenderWindow& window)
{
    for (vector<ParticleSystem*>::iterator it = m_particleSystems.begin(); it != m_particleSystems.end(); ++it)
    {
        (*it)->draw(window);
    }

    window.draw(uiText);
}

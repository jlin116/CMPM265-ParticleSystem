#pragma once
#include "ParticleSystem.h"

class ParticleSystemManager
{
private:
    vector<ParticleSystem*> m_particleSystems;
    unsigned int m_particleAmount;
    Text uiText;
    Font font;

    void updateParticleAmount();

public:
    enum ParticleSystemMode
    {
        INCREASE_SIZE,
        SHRINK_SIZE,
        INCREASE_VELOCITY,
        DECREASE_VELOCITY
    };

    ParticleSystemManager();
    ~ParticleSystemManager();

    void spawnParticleSystem(Vector2f pos, ParticleSystemMode mode);
    void increaseParticleAmount(unsigned int amount);
    void decreaseParticleAmount(unsigned int amount);

    void update(float elapsedTime);
    void draw(RenderWindow& window);
};
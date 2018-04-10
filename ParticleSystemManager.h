#pragma once
#include "ParticleSystem.h"

class ParticleSystemManager
{
private:
    vector<ParticleSystem> m_particleSystems;
    unsigned int m_particleAmount;

    void updateParticleAmount();

public:
    enum ParticleSystemMode
    {
        DEFAULT,
        MODE_1,
        MODE_2
    };

    ParticleSystemManager();

    void spawnParticleSystem(Vector2f pos, ParticleSystemMode mode);
    void increaseParticleAmount(unsigned int amount);
    void decreaseParticleAmount(unsigned int amount);

    void update(float elapsedTime);
    void draw(RenderWindow& window);
};
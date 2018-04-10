#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Particle.h"
#include "IStrategy.h"

using namespace sf;
using namespace std;

class ParticleSystem
{
public:
    ParticleSystem() {};
    ParticleSystem(Vector2f pos, unsigned int count);

    void update(float elapsedTime);
    void draw(RenderWindow& window);
    void changeParticleCount(unsigned int count);
    void setStrategy(IStrategy strategy);

private:
    int m_particleCount;
    vector<Particle*> m_particles;
    Vector2f m_emitLocation;

    float m_startAngle;
    Color m_emissionColor;
    unsigned int m_spawnControl;

    IStrategy m_strategy;

    void fillParticleSystem();
};
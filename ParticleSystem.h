#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem
{
public:
    ParticleSystem() {};
    ParticleSystem(Vector2f pos, unsigned int count);

    void update(float elapsedTime);
    void draw(RenderWindow& window);

private:
    int m_particleCount;
    vector<Particle*> m_particles;
    Vector2f m_emitLocation;

    void fillParticleSystem();
};
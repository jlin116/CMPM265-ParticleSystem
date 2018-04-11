#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Particle.h"
#include "IBehaviour.h"

using namespace sf;
using namespace std;

class ParticleSystem
{
public:
    ParticleSystem() {};
    ParticleSystem(Vector2f pos, unsigned int count);
    ~ParticleSystem();

    void update(float elapsedTime);
    void draw(RenderWindow& window);
    void changeParticleCount(unsigned int count);
    void setBehaviour(IBehaviour *behaviour);

protected:
    virtual void lerp() { };

private:
    int m_particleCount;
    vector<Particle*> m_particles;
    Vector2f m_emitLocation;

    float m_startAngle;
    Color m_emissionColor;
    unsigned int m_spawnControl;

    IBehaviour* m_behaviour;

    void fillParticleSystem();
};
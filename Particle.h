#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Particle : public RectangleShape
{
private:
    Vector2f m_position;
    Vector2f m_velocity;
    Vector2f m_acceleration;

    float m_lifespan;

public:
    Particle() {};
    Particle(Vector2f pos);

    void update(float elapsedTime);
    bool checkLifespan();
};

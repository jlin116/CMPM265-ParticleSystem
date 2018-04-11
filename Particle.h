#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Particle : public RectangleShape
{
private:
    Vector2f m_position;
    Vector2f m_acceleration;

public:
    Vector2f m_velocity;
    float m_duration;
    float m_lifespan;

    Particle() {};
    Particle(Vector2f pos, float startAngle, Color c);

    void update(float elapsedTime);
    bool checkLifespan();
};

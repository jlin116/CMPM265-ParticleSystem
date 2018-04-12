#include "Particle.h"
#include <iostream>

#define LIFE_SPAN_MIN_MS 500
#define LIFE_SPAN_MAX_MS 3000

#define PARTICLE_SIZE 5

Particle::Particle(Vector2f pos, float startAngle, Color c)
{
    m_position = pos;

    float angle = ((std::rand() % 50) + startAngle) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    m_velocity = Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    m_initSpeed = m_velocity;

    // Simulate downward gravity
    m_acceleration = Vector2f(0, 0.5f);

    // Random lifespan between min and max in milliseconds
    m_lifespan = (float)(std::rand() % (LIFE_SPAN_MAX_MS - LIFE_SPAN_MIN_MS + 1) + LIFE_SPAN_MIN_MS);
    m_duration = m_lifespan;

    // Initialize SFML drawable
    setSize(Vector2f(PARTICLE_SIZE, PARTICLE_SIZE));
    setOrigin(Vector2f(PARTICLE_SIZE / 2, PARTICLE_SIZE / 2));
    setFillColor(c);
    setPosition(m_position);
}

void Particle::update(float elapsedTime)
{
    m_velocity += m_acceleration;
    m_position += m_velocity * elapsedTime;
    m_lifespan -= elapsedTime * 1000;

    setPosition(m_position);
}

bool Particle::checkLifespan()
{
    if (m_lifespan <= 0)
    {
        return false;
    }

    return true;
}


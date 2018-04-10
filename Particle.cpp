#include "Particle.h"
#include <iostream>

#define LIFE_SPAN_MIN_MS 500
#define LIFE_SPAN_MAX_MS 3000

#define PARTICLE_SIZE 2

Particle::Particle(Vector2f pos)
{
    // Initialize particle metadata
    m_position = pos;

    // Random emitting angle and speed
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    m_velocity = Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

    // Simulate downward gravity
    m_acceleration = Vector2f(0, 0.05f);

    // Random lifespan between min and max in milliseconds
    m_lifespan = (float)(std::rand() % (LIFE_SPAN_MAX_MS - LIFE_SPAN_MIN_MS + 1) + LIFE_SPAN_MIN_MS);

    // Initialize SFML drawable
    setSize(Vector2f(PARTICLE_SIZE, PARTICLE_SIZE));
    setOrigin(Vector2f(PARTICLE_SIZE / 2, PARTICLE_SIZE / 2));
    setFillColor(Color::Red);
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


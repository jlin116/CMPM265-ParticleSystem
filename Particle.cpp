#include "Particle.h"

Particle::Particle(Vector2f pos)
{
    position = pos;
    velocity = Vector2f(0, 0);
    acceleration = Vector2f(0, 0);

    lifespan = 255;
}

void Particle::update(float elapsedTime)
{

}

Drawable* Particle::display()
{

}

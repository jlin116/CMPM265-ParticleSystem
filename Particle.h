#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Particle : RectangleShape
{
private:
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    float lifespan;

public:
    Particle();
    Particle(Vector2f pos);

    void update(float elapsedTime);

    Drawable* display();
};

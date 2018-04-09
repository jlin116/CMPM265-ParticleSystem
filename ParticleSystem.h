#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable, public sf::Transformable
{
public:
    ParticleSystem(unsigned int count);

    void setEmitter(Vector2f position);

    void update(Time elapsed);

private:
    struct Particle
    {
        Vector2f velocity;
        Time lifetime;
    };

    void resetParticle(std::size_t index);

    vector<Particle> m_particles;
    VertexArray m_vertices;
    Time m_lifetime;
    Vector2f m_emitter;
};
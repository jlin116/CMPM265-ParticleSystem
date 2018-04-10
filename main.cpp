
#include "main.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGH 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "ParticleSystem");
    sf::Clock clock;

    particle = Particle(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGH / 2));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float elapsedTime = clock.restart().asSeconds();

        update(elapsedTime);

        draw(window);
    }

    return 0;
}

void update(float elapsedTime)
{
    particle.update(elapsedTime);
}

void draw(RenderWindow& window)
{
    window.clear();

    window.draw(particle);

    window.display();
}


#include "main.h"
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGH 600
#define DEFAULT_PARTICLE_AMOUNT 2000
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "ParticleSystem");
    sf::Clock clock;

    particleSystem = ParticleSystem(Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGH/2), DEFAULT_PARTICLE_AMOUNT);
    srand(time(NULL));

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
    particleSystem.update(elapsedTime);
}

void draw(RenderWindow& window)
{
    window.clear();

    particleSystem.draw(window);

    window.display();
}


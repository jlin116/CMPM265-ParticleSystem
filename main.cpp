#include "main.h"
#include <stdlib.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGH 600

#define PARTICLE_AMOUNT_CHANGE_AMOUNT 1000

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "ParticleSystem");
    sf::Clock clock;

    srand(time(NULL));
    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::DEFAULT;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handling mouse click event for emitting location
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Mouse Clicked" << endl;
                    m_particleSystemManager.spawnParticleSystem(Vector2f(event.mouseButton.x, event.mouseButton.y), m_particleSystemMode);
                }
            }

            // Handling key press event for changing modes and increase/decrease particles
            if (event.type == sf::Event::KeyPressed)
            {
                // Increase particle amount
                if (event.key.code == sf::Keyboard::Up)
                {
                    std::cout << "Increase Amount" << endl;
                    m_particleSystemManager.increaseParticleAmount(PARTICLE_AMOUNT_CHANGE_AMOUNT);
                }

                // Decrease particle amount
                if (event.key.code == sf::Keyboard::Down)
                {
                    std::cout << "Decrease Amount" << endl;
                    m_particleSystemManager.decreaseParticleAmount(PARTICLE_AMOUNT_CHANGE_AMOUNT);
                }

                // 3 Types of particle systems
                if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Num3)
                {

                }
            }
        }

        float elapsedTime = clock.restart().asSeconds();

        // Update particle system logics
        m_particleSystemManager.update(elapsedTime);

        // Refresh diplay
        window.clear();
        m_particleSystemManager.draw(window);
        window.display();
    }

    return 0;
}

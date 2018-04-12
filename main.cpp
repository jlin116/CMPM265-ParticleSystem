#include "main.h"
#include <stdlib.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGH 600

#define PARTICLE_AMOUNT_CHANGE_AMOUNT 50

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "ParticleSystem");
    sf::Clock clock;

    srand((unsigned int)time(NULL));
    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::INCREASE_SIZE;

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
                    m_particleSystemManager.spawnParticleSystem(Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y), m_particleSystemMode);
                }
            }

            // Handling key press event for changing modes and increase/decrease particles
            if (event.type == sf::Event::KeyPressed)
            {
                // Increase particle amount
                if (event.key.code == sf::Keyboard::Up)
                {
                    m_particleSystemManager.increaseParticleAmount(PARTICLE_AMOUNT_CHANGE_AMOUNT);
                }

                // Decrease particle amount
                if (event.key.code == sf::Keyboard::Down)
                {
                    m_particleSystemManager.decreaseParticleAmount(PARTICLE_AMOUNT_CHANGE_AMOUNT);
                }

                // 4 Types of particle systems
                if (event.key.code == sf::Keyboard::Num1)
                {
                    std::cout << "ParticleSystem Increasing Size" << endl;
                    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::INCREASE_SIZE;
                }
                if (event.key.code == sf::Keyboard::Num2)
                {
                    std::cout << "ParticleSystem Decreasing Size" << endl;
                    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::SHRINK_SIZE;
                }
                if (event.key.code == sf::Keyboard::Num3)
                {
                    std::cout << "ParticleSystem Increasing Velocity" << endl;
                    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::INCREASE_VELOCITY;
                }
                if (event.key.code == sf::Keyboard::Num4)
                {
                    std::cout << "ParticleSystem Decreasing Velocity" << endl;
                    m_particleSystemMode = ParticleSystemManager::ParticleSystemMode::DECREASE_VELOCITY;
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

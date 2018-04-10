#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

ParticleSystem particleSystem;

void update(float elapsedTime);
void draw(RenderWindow& window);

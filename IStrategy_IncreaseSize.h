#pragma once
#include "IStrategy.h"

class IStrategy_IncreaseSize : public IStrategy
{
private:
public:
    void change(Particle& particle, float elapsedTime) override;
};
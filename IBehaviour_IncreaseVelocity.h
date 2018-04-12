#pragma once
#include "IBehaviour.h"

class IBehaviour_IncreaseVelocity : public IBehaviour
{
public:
    IBehaviour_IncreaseVelocity() {};
    virtual void lerp(Particle& particle) override;
};

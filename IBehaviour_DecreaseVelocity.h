#pragma once
#include "IBehaviour.h"

class IBehaviour_DecreaseVelocity : public IBehaviour
{
public:
    IBehaviour_DecreaseVelocity() {};
    virtual void lerp(Particle& particle) override;
};

#pragma once

#include "IBehaviour.h"

class IBehaviour_IncreaseSize : public IBehaviour
{
private:
    Vector2f m_maxSize;

public:
    IBehaviour_IncreaseSize() {};
    IBehaviour_IncreaseSize(Vector2f maxSize);
    virtual void lerp(Particle& particle) override;
};
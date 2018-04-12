#pragma once
#include "IBehaviour.h"

class IBehaviour_DecreaseSize : public IBehaviour
{
private:
    Vector2f m_minSize;

public:
    IBehaviour_DecreaseSize();

    virtual void lerp(Particle& particle) override;
};
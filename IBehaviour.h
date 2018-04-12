#pragma once
#include "Particle.h"

class IBehaviour
{
protected:
    typedef IBehaviour super;
    float m_timeFrac;

public:
    IBehaviour() { };
    virtual void lerp(Particle& particle)
    {
        m_timeFrac = (particle.m_duration - particle.m_lifespan) / particle.m_duration;
    };
};
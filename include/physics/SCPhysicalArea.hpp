#ifndef SCPhysicalArea_HPP
#define SCPhysicalArea_HPP

#include <SFML/Window.hpp>

struct SCPhysicState
{
    float m_x;
    float m_v;
    float m_f;
    float m_m;

    SCPhysicState& operator =(const SCPhysicState & A)
    {
        m_x = A.m_x;
        m_v = A.m_v;
        m_f = A.m_f;
        m_m = A.m_m;
        return *this;
    }
};

class SCPhysicalArea
{
    SCPhysicState m_pstate;
    sf::Clock m_clock;
    sf::Time m_dt;
    sf::Time m_maxSimFrameTime;
    sf::Time m_tCurrent;
    sf::Time m_tAcc;

    public:
        SCPhysicalArea();
        SCPhysicalArea loop();
        void integrate();
        SCPhysicState getState() { return m_pstate; }
        void eventHandler(sf::Event & e);

        SCPhysicalArea& operator =(const SCPhysicalArea & A)
        {
            m_pstate = A.m_pstate;
            return *this;
        }

        SCPhysicalArea operator *(const double & A)
        {
            SCPhysicalArea modifWorld(*this);
            modifWorld.m_pstate.m_x *= A;
            modifWorld.m_pstate.m_v *= A;
            return modifWorld;
        }

        SCPhysicalArea operator +(const SCPhysicalArea & A)
        {
            SCPhysicalArea modifWorld(*this);
            modifWorld.m_pstate.m_x += A.m_pstate.m_x;
            modifWorld.m_pstate.m_v += A.m_pstate.m_v;
            return modifWorld;
        }

        SCPhysicalArea operator -(const SCPhysicalArea & A)
        {
            SCPhysicalArea modifWorld(*this);
            modifWorld.m_pstate.m_x -= A.m_pstate.m_x;
            modifWorld.m_pstate.m_v -= A.m_pstate.m_v;
            return modifWorld;
        }
};

#endif
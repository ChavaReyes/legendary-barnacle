#include "SCPhysicalArea.hpp"

SCPhysicalArea::SCPhysicalArea()
{
    m_pstate.m_x = 0.0f;
    m_pstate.m_v = 0.0f;
    m_pstate.m_f = 0.0f;
    m_pstate.m_m = 1.0f;

    m_dt = sf::milliseconds(10);
    m_maxSimFrameTime = sf::milliseconds(250);

    m_tCurrent = m_clock.getElapsedTime();
    m_tAcc = sf::Time::Zero;
}

SCPhysicalArea& SCPhysicalArea::loop()
{
    sf::Time newTime = m_clock.getElapsedTime();
    sf::Time simulationFrameTime = newTime - m_tCurrent;

    if (simulationFrameTime > m_maxSimFrameTime)
    {
        simulationFrameTime = m_maxSimFrameTime;
    }
    m_tCurrent = newTime;

    m_tAcc += simulationFrameTime;

    SCPhysicalArea previousPWorld;
    while ( m_tAcc >= m_dt )
    {
        previousPWorld = *this;
        integrate();
        m_tAcc -= m_dt;
    }

    const float alpha = m_tAcc / m_dt;

    //( *this ) * alpha + previousPWorld * ( 1.0f - alpha );
    //(m_currentPhWorld - m_previousPhWorld) * alpha + m_previousPhWorld;

    return *this = ( *this ) * alpha + previousPWorld * ( 1.0f - alpha );
}

void SCPhysicalArea::integrate()
{
    m_pstate.m_v += ( m_pstate.m_f / m_pstate.m_m ) * m_dt.asSeconds();
    m_pstate.m_x += m_pstate.m_v * m_dt.asSeconds();
}

void SCPhysicalArea::eventHandler(sf::Event & e)
{
    switch(e.type)
    {
        case sf::Event::KeyPressed:

            switch(e.key.code)
            {
                case sf::Keyboard::Right:
                    m_pstate.m_f += 1;
                break;

                case sf::Keyboard::Left:
                    m_pstate.m_f -= 1;
                break;

                default:
                    
                break;
            }
            
        break;

        default:
            if(m_pstate.m_v > 2.0f)
            {
                m_pstate.m_v -= 2.0f;
            }
            else if(m_pstate.m_v < -2.0f)
            {
                ++m_pstate.m_v += 2.0f;
            }
            else
            {
                m_pstate.m_v = 0.0f;
            }
            
        break;
    }
}
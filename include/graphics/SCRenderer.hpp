#ifndef SCRENDERER_HPP
#define SCRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "SCScreen.hpp"

class SCPhysicalArea;

class SCRenderer
{
    sf::RenderWindow* m_renderWindow;
    unsigned short m_fps;
    double m_framePeriod;
    double m_startFrameTime;
    SCScreen m_screen;

    public:
        SCRenderer(sf::RenderWindow * renderWindow);
        void render(SCPhysicalArea & pWorld);
};

#endif
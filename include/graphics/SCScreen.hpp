#ifndef SCSCREEN_HPP
#define SCSCREEN_HPP

#include "../physics/SCPhysicalObject.hpp"
#include <SFML/Graphics.hpp>

class SCPhysicalArea;

class SCScreen
{
    sf::Font font;
    sf::Text m_text;
    SCPhysicalObject * m_poThing;

    public:
        SCScreen();
        ~SCScreen();

        void clear();
        void render(sf::RenderWindow * renderWindow, SCPhysicalArea & pWorld);
};

#endif
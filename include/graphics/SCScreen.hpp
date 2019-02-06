#ifndef SCSCREEN_HPP
#define SCSCREEN_HPP

#include <SFML/Graphics.hpp>

class SCPhysicalArea;

class SCScreen
{
    sf::Font font;
    sf::Text m_text;

    public:
        SCScreen();

        void clear();
        void render(sf::RenderWindow * renderWindow, SCPhysicalArea & pWorld);
};

#endif
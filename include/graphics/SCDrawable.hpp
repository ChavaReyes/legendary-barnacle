#ifndef SCDRAWABLE_HPP
#define SCDRAWABLE_HPP

#include <SFML/Graphics.hpp>

class SCDrawable
{
    public:
        virtual void render(sf::RenderWindow * renderWindow) {}
};

#endif
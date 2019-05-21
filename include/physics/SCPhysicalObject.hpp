#ifndef SCPHYSICALOBJECT_HPP
#define SCPHYSICALOBJECT_HPP

#include "../graphics/SCDrawable.hpp"
#include "SCPhysicalArea.hpp"
#include <SFML/Graphics.hpp>

class SCPhysicalObject : public SCDrawable
{
    public:
        SCPhysicState   m_psState;
        sf::Drawable * m_dShape;

        SCPhysicalObject();
        SCPhysicalObject(sf::Drawable * dShape);
        void render(sf::RenderWindow * renderWindow);
};

#endif
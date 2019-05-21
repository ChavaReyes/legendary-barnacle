#include "SCPhysicalObject.hpp"

SCPhysicalObject::SCPhysicalObject()
{
    
}

SCPhysicalObject::SCPhysicalObject(sf::Drawable * dShape)
{
    m_dShape = dShape;
}

void SCPhysicalObject::render(sf::RenderWindow * renderWindow)
{
    if (m_dShape)
    {
        renderWindow->draw(*m_dShape);
    }
}
#include "SCScreen.hpp"
#include "../physics/SCPhysicalArea.hpp"
#include "../utilities/SCUtilities.hpp"
#include <sstream>

SCScreen::SCScreen()
{
    font.loadFromFile("../resources/fonts/arial.ttf");
    m_text.setFont(font);
    m_text.setPosition({ 0.0f, 100.0f });
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::Black);

    sf::RectangleShape * rectangle = new sf::RectangleShape({ 100, 100 });
    rectangle->setFillColor(sf::Color::Black);
    m_poThing = new SCPhysicalObject(rectangle);
}

SCScreen::~SCScreen()
{
    if (m_poThing)
    {
        delete m_poThing;
    }
}

void SCScreen::clear()
{
    //pending
}

void SCScreen::render(sf::RenderWindow * renderWindow, SCPhysicalArea & pWorld)
{
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(3);

    SCPhysicState state = pWorld.getState();
    std::cout << "Position: " << pWorld.getState().m_x << "\r";
    */
    std::ostringstream buff;
    buff << pWorld.getState().m_f;
    m_text.setString("Force: " + buff.str());

    sf::Vector2f pos = m_text.getPosition();
    pos.x = pWorld.getState().m_x;
    m_text.setPosition(pos);

    renderWindow->draw(m_text);

    if (m_poThing)
    {
        m_poThing->render(renderWindow);
    }
}
#include "SCGame.hpp"
#include "../utilities/SCUtilities.hpp"
#include <SFML/Graphics.hpp>

SCGame::SCGame()
{
}

void SCGame::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Legendary Barnacle");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    SCRenderer renderer(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            m_PhWorld.eventHandler(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        SCPhysicalArea tmpPWorld = m_PhWorld.loop();
        renderer.render(tmpPWorld);

        window.display();
    }
}
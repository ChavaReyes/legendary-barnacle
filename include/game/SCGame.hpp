#ifndef SCGAME_HPP
#define SCGAME_HPP

#include "../physics/SCPhysicalArea.hpp"
#include "../graphics/SCRenderer.hpp"

class SCGame
{
    SCPhysicalArea m_PhWorld;

    public:
        SCGame();
        void run();
        void eventHandler(sf::Event & e);
};

#endif
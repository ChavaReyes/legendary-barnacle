#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CONSOLE_WIDTH 300

#include <catch.hpp>
#include <SFML/Window.hpp>
#include "../include/physics/SCPhysicalArea.hpp"

TEST_CASE( "Physical Area Tests", "[physics]" ) {
    SCPhysicalArea aPhysicalArea;
    aPhysicalArea.loop();

    REQUIRE( aPhysicalArea.getState().m_x == 0 );
}
cmake_minimum_required(VERSION 3.13.3)
project (legendary-barnacle)

# cmake .. -G "MinGW Makefiles"
# mingw32-make

set(SFML_DIR libs/SFML-2.5.1/lib/cmake/SFML)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

include_directories(include)
include_directories(libs/SFML-2.5.1/src)
#include_directories(${SFML_INCLUDE_DIR}) # You forgot this line above; add SFML's include dir
include_directories(libs/Catch2)

set(SOURCES 
    main.cpp 
    include/game/SCGame.cpp
    include/graphics/SCRenderer.cpp
    include/graphics/SCScreen.cpp
    include/physics/SCPhysicalArea.cpp
    include/physics/SCPhysicalObject.cpp
    include/utilities/SCUtilities.cpp
)

set(TESTS_SOURCES
    tests/tests.cpp
    include/physics/SCPhysicalArea.cpp
)

add_executable(Legendary_Barnacle ${SOURCES})
add_executable(Tests ${TESTS_SOURCES} libs/Catch2/catch.hpp)

target_link_libraries(Legendary_Barnacle sfml-graphics)
target_link_libraries(Tests sfml-window)
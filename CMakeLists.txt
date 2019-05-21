cmake_minimum_required(VERSION 3.13.3)
project (legendary-barnacle)

# cmake .. -G "MinGW Makefiles"
# mingw32-make

include_directories(include)
include_directories(C:/SFML-2.5.1/include)
include_directories(C:/Catch2)

link_directories(C:/SFML-2.5.1/lib)

#file(GLOB SOURCES "include/game/*.cpp")
set(SFML_INCLUDE C:/SFML-2.5.1/include/SFML)

set(SOURCES 
    main.cpp 
    include/game/SCGame.cpp
    include/graphics/SCRenderer.cpp
    include/graphics/SCScreen.cpp
    include/physics/SCPhysicalArea.cpp
    include/physics/SCPhysicalObject.cpp
    include/utilities/SCUtilities.cpp
    ${SFML_INCLUDE}/System.hpp
    ${SFML_INCLUDE}/Window.hpp
    ${SFML_INCLUDE}/Graphics.hpp
)

set(TESTS_SOURCES
    tests/tests.cpp
    include/physics/SCPhysicalArea.cpp
    ${SFML_INCLUDE}/Window.hpp
)

# set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(PROJECT_LINK_LIBS libsfml-system-d.a libsfml-window-d.a libsfml-graphics-d.a)

add_executable(Legendary_Barnacle ${SOURCES})
add_executable(Tests ${TESTS_SOURCES} C:/Catch2/catch.hpp)

target_link_libraries(Legendary_Barnacle ${PROJECT_LINK_LIBS})
target_link_libraries(Tests ${PROJECT_LINK_LIBS})
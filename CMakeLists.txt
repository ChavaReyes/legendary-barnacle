cmake_minimum_required(VERSION 3.13.3)
project (legendary-barnacle)

# cmake .. -G "MinGW Makefiles"
# mingw32-make

include_directories(include)
include_directories(C:/SFML-2.5.1/include)
#file(GLOB SOURCES "include/game/*.cpp")
set(SOURCES 
    main.cpp 
    include/game/SCGame.cpp
    include/graphics/SCRenderer.cpp
    include/graphics/SCScreen.cpp
    include/physics/SCPhysicalArea.cpp
    include/utilities/SCUtilities.cpp
    C:/SFML-2.5.1/include/SFML/System.hpp
    C:/SFML-2.5.1/include/SFML/Window.hpp
    C:/SFML-2.5.1/include/SFML/Graphics.hpp
)

# set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(PROJECT_LINK_LIBS libsfml-system-d.a libsfml-window-d.a libsfml-graphics-d.a)
link_directories(C:/SFML-2.5.1/lib)

add_executable(Legendary_Barnacle ${SOURCES})

target_link_libraries(Legendary_Barnacle ${PROJECT_LINK_LIBS})
cmake_minimum_required(VERSION 3.13.3)
project (legendary-barnacle)

# cmake .. -G "MinGW Makefiles"
# mingw32-make

#set(CMAKE_MODULE_PATH libs/SFML-2.5.1/lib/cmake) # Tell CMake where to find the module
set(SFML_DIR libs/SFML-2.5.1/lib/cmake/SFML)
set(CMAKE_LIBRARY_PATH "${CMAKE_CURRENT_LIST_DIR}/../..")
#set(SFML_DIR libs/SFML-2.5.1)
#set(SFML_INCLUDE libs/SFML-2.5.1/include/SFML)
#set(CMAKE_PREFIX_PATH libs/SFML-2.5.1/lib/cmake)
#find_package(SFML REQUIRED COMPONENTS graphics window system) # Look for SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)
#find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)
include_directories(libs/SFML-2.5.1/src)
#include_directories(${SFML_INCLUDE_DIR}) # You forgot this line above; add SFML's include dir
include_directories(libs/Catch2)

#link_directories(libs/SFML-2.5.1/lib)

#file(GLOB SOURCES "include/game/*.cpp")

set(SOURCES 
    main.cpp 
    include/game/SCGame.cpp
    include/graphics/SCRenderer.cpp
    include/graphics/SCScreen.cpp
    include/physics/SCPhysicalArea.cpp
    include/physics/SCPhysicalObject.cpp
    include/utilities/SCUtilities.cpp
    #${SFML_INCLUDE}/System.hpp
    #${SFML_INCLUDE}/Window.hpp
    #${SFML_INCLUDE}/Graphics.hpp
)

set(TESTS_SOURCES
    tests/tests.cpp
    include/physics/SCPhysicalArea.cpp
    #${SFML_INCLUDE}/Window.hpp
)

add_executable(Legendary_Barnacle ${SOURCES})
add_executable(Tests ${TESTS_SOURCES} libs/Catch2/catch.hpp)

#set(SFML_DEPENDENCIES opengl32 winmm gdi32)
#set(PROJECT_LINK_LIBS libsfml-system-s-d.a libsfml-window-s-d.a libsfml-graphics-s-d.a)
target_link_libraries(Legendary_Barnacle sfml-graphics)
#target_link_libraries(Legendary_Barnacle sfml-graphics ${SFML_DEPENDENCIES})
#target_link_libraries(Legendary_Barnacle ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}) # Link SFML and dependencies
#target_link_libraries(Legendary_Barnacle SFML::graphics SFML::window SFML::system)
target_link_libraries(Tests sfml-window)
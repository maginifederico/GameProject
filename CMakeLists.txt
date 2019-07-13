cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Layer.h GameCharacter.h Obstacle.h Item.h GameHero.h Map.h)
add_executable(Game ${SOURCE_FILES} GameHero.cpp Obstacle.cpp Item.cpp GameHero.cpp Tile.cpp Tile.h Layer.cpp GameCharacter.cpp Map.cpp Collision.cpp Collision.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()


add_subdirectory(test)

#set(SOURCE_FILES header e source tutti per googletest)
add_executable(patagame_unit_testing main.cpp)
add_library(core ${SOURCE_FILES} Layer.h)
target_link_libraries(patagame_unit_testing core)
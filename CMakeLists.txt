cmake_minimum_required(VERSION 3.7)
project(Game)
set(CMAKE_CXX_STANDARD 11)

add_executable(Game main.cpp Layer.h Obstacle.h Item.h GameHero.h Map.h GameHero.cpp Obstacle.cpp Item.cpp GameHero.cpp Tile.cpp Tile.h Layer.cpp GameCharacter.cpp GameCharacter.h Map.cpp Weapon.cpp Weapon.h Projectile.cpp Projectile.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()

#PER GOOGLE TEST SCOMMENTARE TUTTE LE ISTRUZIONI SEGUENTI. PER UNIT TESTING VEDI LIBRO DA PAGINA 248

# Add GoogleTest
add_subdirectory(test)

#aggiungere all'istruzione seguente i file da sottoporre a test
set(SOURCE_FILES GameHero.h GameHero.cpp GameCharacter.h GameCharacter.cpp Map.h Map.cpp Layer.h Layer.cpp Tile.h Tile.cpp)
add_executable(patagame_unit_testing main.cpp ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(patagame_unit_testing core sfml-graphics sfml-window sfml-system sfml-audio)


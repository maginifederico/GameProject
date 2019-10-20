cmake_minimum_required(VERSION 3.7)
project(Game)
set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES Layer.h Layer.cpp Obstacle.h Item.h GameHero.h Map.h GameHero.cpp Obstacle.cpp Item.cpp
        GameHero.cpp Tile.cpp Tile.h GameCharacter.cpp GameCharacter.h Map.cpp Weapon.cpp Weapon.h Projectile.cpp
        Projectile.h WeaponFactory.h ObjectFactory.h Coin.cpp Coin.h MapFactory.h HealthPill.h HealthPill.cpp Spike.cpp
        Spike.h Checkpoint.cpp Checkpoint.h Gui.cpp Gui.h StoneGenerator.cpp StoneGenerator.h Stone.cpp Stone.h
        BlueFlag.cpp BlueFlag.h Door.cpp Door.h DoorFactory.h Bonus.cpp Bonus.h Enemy.h
        Enemy.cpp MovementBehaviour.h MovementBehaviour.cpp EnemyFactory.h WalkingBehaviour.h WalkingBehaviour.cpp
        FlyingBehaviour.h FlyingBehaviour.cpp StillBehaviour.cpp StillBehaviour.h EnemyFactory.cpp MapFactory.cpp DoorFactory.cpp WeaponFactory.cpp ObjectFactory.cpp
        Subject.cpp Subject.h Observer.cpp Observer.h State.h State.cpp MenuModel.h MenuModel.cpp MenuView.h MenuView.cpp MenuController.h MenuController.cpp
        MenuState.h MenuState.cpp LevelState.h LevelState.cpp Level.h Level.cpp)


add_executable(Game main.cpp ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()

#GOOGLE TEST. PER UNIT TESTING VEDI LIBRO DA PAGINA 248
# Add GoogleTest
add_subdirectory(test)
add_executable(patagame_unit_testing main.cpp ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(patagame_unit_testing core sfml-graphics sfml-window sfml-system sfml-audio)


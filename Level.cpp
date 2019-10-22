/**
 * Project Untitled
 */


#include "Level.h"
#include "StillBehaviour.h"

/**
 * Level implementation
 */

Level::Level() {

    map = nullptr;
    mapId = -1;

}

void Level::loadMap(int levelNumber, GameHero &player/*, int weapon*/) {

    mapId = levelNumber;
//    weaponId = weapon;

    ////INIT MAP
    if (map != nullptr)
        delete map;
    map = mapFactory.createMap(mapId);

    ////INIT ENEMIES

    StillBehaviour *behaviour;
    for (Enemy *enemy : map->getEnemies()) {

        behaviour = dynamic_cast<StillBehaviour *>(enemy->getMovementBehaviour());
        if (behaviour != nullptr)
            behaviour->setPlayer(&player);

    }
}

Map *Level::getMap() {
    return map;
}

void Level::manageDoors(GameHero &player) {

    ////DOOR MANAGEMENT
    float defaultDistanceX = 126.f;
    float defaultDistanceY = 40.f;

    for (Door *door : map->getDoors()) {
        if (player.getSprite().getGlobalBounds().intersects(door->getCollision())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (!door->isDisabled()) {

                    loadMap(door->getNextMapId(), player);

                    player.setHP(100, *map);
                    player.getSprite().setPosition(door->getNextSpawnPoint());

                    player.getPlayerView().setCenter(player.getSprite().getPosition().x + defaultDistanceX,
                                                     player.getSprite().getPosition().y - defaultDistanceY);

                    if (player.getPlayerView().getCenter().x - player.getPlayerView().getSize().x / 4 <
                        map->getViewHorizontalLimitSx())
                        player.getPlayerView().setCenter(player.getPlayerView().getSize().x / 2,
                                                         player.getPlayerView().getCenter().y);
                    if (player.getPlayerView().getCenter().x - player.getPlayerView().getSize().x / 4 >
                        map->getViewHorizontalLimitDx())
                        player.getPlayerView().setCenter(
                                map->getWidth() - player.getPlayerView().getSize().x / 2,
                                player.getPlayerView().getCenter().y);
                    if (player.getPlayerView().getCenter().y + 40.f > map->getViewVerticalLimitDown())
                        player.getPlayerView().setCenter(player.getPlayerView().getCenter().x,
                                                         map->getHeight() -
                                                         player.getPlayerView().getSize().y / 2);
                    if (player.getPlayerView().getCenter().y + 40.f < map->getViewVerticalLimitUp())
                        player.getPlayerView().setCenter(player.getPlayerView().getCenter().x,
                                                         player.getPlayerView().getSize().y / 2);

                    player.getGui().reset();

                    player.getGui().load(player.getPlayerView());
                    break;
                }
            }
        }
    }

}

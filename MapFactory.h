//
// Created by federico on 20/09/19.
//

#ifndef GAME_MAPFACTORY_H
#define GAME_MAPFACTORY_H

#include <bits/unique_ptr.h>


class MapFactory {

public:

//    std::unique_ptr<Map> createMap(int id);
    Map *createMap(int id);

};

//std::unique_ptr<Map> MapFactory::createMap(int id) {
Map *MapFactory::createMap(int id) {

//    std::unique_ptr<Map> result;
    Map *result;

    switch (id) {

        case 1: {

            float mapWidth = 6300.f;
            float mapHeight = 525.f;
            sf::Vector2f spawnPoint(100.f, 300.f);

            result = new Map(mapWidth, mapHeight, spawnPoint, "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt",
                             "./Map/objectsLevel1");

            result->load();

            break;

        }

        case 2: {

            float mapWidth = 1470.f;
            float mapHeight = 840.f;
            sf::Vector2f spawnPoint(84.f, 672.f);

            result = new Map(mapWidth, mapHeight, spawnPoint, "./Map/caveBackgroundL1.txt", "./Map/caveGroundL1.txt",
                             "./Map/caveObjectsL1.txt");

            result->load();

            break;

        }

        default:
            result = nullptr;
    }

    return result;

}


#endif //GAME_MAPFACTORY_H

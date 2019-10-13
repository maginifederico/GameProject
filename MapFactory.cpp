//
// Created by federico on 11/10/19.
//

#include "MapFactory.h"
#include "Map.h"

//std::unique_ptr<Map> MapFactory::createMap(int id) {
Map *MapFactory::createMap(int id) {

//    std::unique_ptr<Map> result;
    Map *result;

    switch (id) {

        case 1: {

            float mapWidth = 6300.f;
            float mapHeight = 525.f;
            sf::Vector2f spawnPoint(100.f, 300.f);

//            result = std::unique_ptr<Map> (new Map(mapWidth, mapHeight, spawnPoint, "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt",
//                                                   "./Map/objectsLevel1"));
            result = new Map(mapWidth, mapHeight, spawnPoint, "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt",
                             "./Map/objectsLevel1", id);

            result->load();
            result->setViewLimits();


            break;

        }

        case 2: {

            float mapWidth = 1470.f;
            float mapHeight = 840.f;
            sf::Vector2f spawnPoint(84.f, 672.f);

//            result = std::unique_ptr<Map> (new Map(mapWidth, mapHeight, spawnPoint, "./Map/caveBackgroundL1.txt", "./Map/caveGroundL1.txt",
//                                          "./Map/caveObjectsL1.txt"));
            result = new Map(mapWidth, mapHeight, spawnPoint, "./Map/caveBackgroundL1.txt", "./Map/caveGroundL1.txt",
                             "./Map/caveObjectsL1.txt", id);

            result->load();
            result->setViewLimits();


            break;

        }

        case 3: {

            float mapWidth = 1050.f;
            float mapHeight = 1155.f;
            sf::Vector2f spawnPoint(84.f, 945.f);

//            result =std::unique_ptr<Map> (new Map(mapWidth, mapHeight, spawnPoint, "./Map/undergroundBackgroundL1.txt",
//                                                  "./Map/undergroundGroundL1.txt", "./Map/undergroundObjectsL1.txt"));
            result = new Map(mapWidth, mapHeight, spawnPoint, "./Map/undergroundBackgroundL1.txt",
                             "./Map/undergroundGroundL1.txt", "./Map/undergroundObjectsL1.txt", id);

            result->load();
            result->setViewLimits();


            break;

        }

        default:
            result = nullptr;
    }

    return result;

}

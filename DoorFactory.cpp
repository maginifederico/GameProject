//
// Created by federico on 11/10/19.
//

#include "DoorFactory.h"
#include "Door.h"

Door *DoorFactory::createDoor(int id, int mapID, int column, float posX, float posY) {

//    std::unique_ptr<Item> result;
    Door *result;

    const int brownDoorID = 54;
    const int blackDoorID = 56;

    //Colonne in cui si trovano le porte nei rispettivi livelli

    //Livello 1
    const int door1L1 = 48;
    const int door2L1 = 260;
    const int door3L1 = 286;

    //Underground
    const int door1UG = 1;

    //Cave
    const int door1C = 3;
    const int door2C = 68;



    //48, 21 prima porta
    switch (mapID) {
        case 1: {
            switch (column) {

                case door1L1: {

                    const int nextMapID = 3;
                    sf::Vector2f nextSpawnPoint(84.f, 945.f);
                    std::string doorTexturePath = "./Textures/BlackDoor.png";

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id);

                    break;

                }

                case door2L1: {

                    const int nextMapID = 2;
                    sf::Vector2f nextSpawnPoint(84.f, 672.f);
                    std::string doorTexturePath = "./Textures/BrownDoor.png";

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id);

                    break;

                }

                case door3L1: {

                    const int nextMapID = 1;
                    sf::Vector2f nextSpawnPoint(0.f, 0.f);
                    std::string doorTexturePath = "./Textures/BrownDoor.png";
                    bool disabled = true;

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id, disabled);

                    break;

                }

                default:
                    result = nullptr;

            }

            break;
        }

        case 2: {
            switch (column) {

                case door1C: {

                    const int nextMapID = 1;
                    sf::Vector2f nextSpawnPoint(0.f, 0.f);
                    std::string doorTexturePath = "./Textures/BrownDoor.png";
                    bool disabled = true;

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id, disabled);

                    break;

                }

                case door2C: {

                    const int nextMapID = 1;
                    //PUNTO IN ALTO
                    sf::Vector2f nextSpawnPoint(0.f, 5.f);
                    std::string doorTexturePath = "./Textures/BrownDoor.png";

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id);

                    break;

                }

                default:
                    result = nullptr;
            }

            break;
        }

        case 3: {
            switch (column) {

                case door1UG: {

                    const int nextMapID = 1;
                    //DOVE C'è la talpa
                    sf::Vector2f nextSpawnPoint(853.5f, 470.f);
                    std::string doorTexturePath = "./Textures/BlackDoor.png";

                    result = new Door(nextSpawnPoint, nextMapID, doorTexturePath, id);

                    break;

                }

                default:
                    result = nullptr;
            }

            break;
        }

        default:
            result = nullptr;
    }

    return result;

}
//
// Created by federico on 28/09/19.
//

#ifndef GAME_DOORFACTORY_H
#define GAME_DOORFACTORY_H


#include "Door.h"

class DoorFactory {

public:
    Door *createDoor(int id, int mapID, int column, float posX, float posY);

};

Door *DoorFactory::createDoor(int id, int mapID, int column, float posX, float posY) {

//    std::unique_ptr<Item> result;
    Door *result;

    const int brownDoorID = 54;
    const int blackDoorID = 56;


    switch (column) {
        case blackDoorID:
        case brownDoorID: {

            std::string doorTexturePath;

            if (id == blackDoorID)
                doorTexturePath = "./Textures/BlackDoor.png";

            if (id == brownDoorID)
                doorTexturePath = "./Textures/BrownDoor.png";


            result = new Door(mapID, 1, doorTexturePath, id);

            break;

        }

        default:
            return nullptr;

    }

//    case id:


    return result;

}

#endif //GAME_DOORFACTORY_H

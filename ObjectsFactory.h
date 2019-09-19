//
// Created by federico on 19/09/19.
//

#ifndef GAME_OBJECTSFACTORY_H
#define GAME_OBJECTSFACTORY_H


#include <bits/unique_ptr.h>
#include "Item.h"
#include "Coin.h"

class ObjectFactory {

public:
    Item *createObject(int id);


};

Item *ObjectFactory::createObject(int id) {

    Item *result;

    const int spikeID = 50;
    const int redFlag = 52;
    const int brownDoorUpID = 54;
    const int brownDoorDownID = 55;
    const int blackDoorUpID = 56;
    const int blackDoorDownID = 57;
    const int healthPillID = 58;
    const int coinID = 59;
    const int blueFlag = 133;

    switch (id) {

        case coinID: {

            int coinValue = 1;
            std::string coinTexturePath = "./Textures/justOne.png";


            result = new Coin(coinValue, coinTexturePath, id);

            break;
        }


        default:
            result = nullptr;


    }

    return result;

}

#endif //GAME_OBJECTSFACTORY_H

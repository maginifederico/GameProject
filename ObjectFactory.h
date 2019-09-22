//
// Created by federico on 19/09/19.
//

#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H


#include <bits/unique_ptr.h>
#include "Item.h"
#include "Coin.h"
#include "HealthPill.h"
#include "Spike.h"
#include "Checkpoint.h"

class ObjectFactory {

public:
    Item *createObject(int id);


};

Item *ObjectFactory::createObject(int id) {

//    std::unique_ptr<Item> result;
    Item *result;

    const int spikeUpID = 50;
    const int spikeDxID = 51;
    const int spikeSxID = 60;
    const int brownDoorUpID = 54;
    const int brownDoorDownID = 55;
    const int blackDoorUpID = 56;
    const int blackDoorDownID = 57;
    const int healthPillID = 58;
    const int coinID = 59;
    const int blueFlag1 = 53;
    const int blueFlag2 = 133;
    const int redFlagLow = 134;
//    const int redFlag1 = 52;
//    const int redFlag2 = 132;


    switch (id) {

        case coinID: {

            int coinValue = 1;
            std::string coinTexturePath = "./Textures/Coin.png";


//            result = std::unique_ptr<Coin>(new Coin(coinValue, coinTexturePath, id));
            result = new Coin(coinValue, coinTexturePath, id);


            break;
        }

        case healthPillID: {

            int healthPillValue = 50;
            std::string healthPillTexturePath = "./Textures/HealthPill.png";


//            result = std::unique_ptr<Coin>(new Coin(coinValue, coinTexturePath, id));
            result = new HealthPill(healthPillValue, healthPillTexturePath, id);


            break;
        }

        case spikeUpID:
        case spikeSxID:
        case spikeDxID: {

            std::string spikeTexturePath;

            if (id == spikeUpID)
                spikeTexturePath = "./Textures/SpikeUP.png";

            if (id == spikeSxID)
                spikeTexturePath = "./Textures/SpikeSX.png";

            if (id == spikeDxID)
                spikeTexturePath = "./Textures/SpikeDX.png";


//            result = std::unique_ptr<Coin>(new Coin(coinValue, coinTexturePath, id));
            result = new Spike(spikeTexturePath, id);


            break;
        }

        case redFlagLow: {

            std::string checkpointTexturePath = "./Textures/RedFlagLow.png";

            result = new Checkpoint(checkpointTexturePath, id);

            break;

        }

        default:
            result = nullptr;


    }

    return result;

}

#endif //GAME_OBJECTFACTORY_H

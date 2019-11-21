//
// Created by federico on 12/10/19.
//


#include "Item.h"
#include "ObjectFactory.h"

Item *ObjectFactory::createObject(int id, float posX, float posY) {

//    std::unique_ptr<Item> result;
    Item *result;

    const int spikeUpID = 50;
    const int spikeDxID = 51;
    const int spikeSxID = 60;
    const int brownDoorID = 54;
//    const int brownDoorDownID = 55;
    const int blackDoorID = 56;
//    const int blackDoorDownID = 57;
    const int healthPillID = 58;
    const int coinID = 59;
    const int blueFlag1 = 53;
    const int blueFlag2 = 133;
    const int stoneID = 135; //Sarebbe lo sprite blueFlagLow
    const int redFlagLow = 134;
    const int attackBonus = 43;
    const int defenceBonus = 45;
//    const int redFlag1 = 52;
//    const int redFlag2 = 132;
//    BONUS


    switch (id) {

        case coinID: {

            int coinValue = 1;
            std::string coinTexturePath = "Textures/Coin.png";


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

        case stoneID: {

            std::string stoneTexturePath = "./Textures/Transparent.png";

            result = new StoneGenerator(posX, posY, stoneTexturePath, id);

            break;

        }

        case blueFlag1:
        case blueFlag2: {

            std::string blueFlagTexturePath = "./Textures/BlueFlag1.png";

            result = new BlueFlag(blueFlagTexturePath, id);

            break;

        }

        case defenceBonus:
        case attackBonus: {

            int bonus;
            sf::Time duration = sf::seconds(5.f);
            std::string bonusTexturePath;

            if (id == attackBonus) {
                bonusTexturePath = "./Textures/AttackBonus.png";
                bonus = 50;
            } else {
                bonusTexturePath = "./Textures/DefenceBonus.png";
                bonus = 50;
            }

            result = new Bonus(bonusTexturePath, bonus, duration, id);

            break;

        }


        default:
            result = nullptr;


    }

    return result;

}
//
// Created by federico on 29/09/19.
//

#include "AttackBonus.h"
#include "GameHero.h"

AttackBonus::AttackBonus(std::string &texturePath, int bonusV, float dur, int id) : Item(texturePath, id),
                                                                                    bonusValue(bonusV),
                                                                                    collectionTime(0.f),
                                                                                    collected(false), duration(dur) {

}

void AttackBonus::interact(GameHero *player, Map &map) {

    collected = true;
    collectionTime = player->getClock().getElapsedTime().asSeconds();

    player->getWeapon()->setAttackBonus(this);


    for (int y = 0; y < map.getObjectsCollector().size(); y++) {
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
        }
    }

}

int AttackBonus::getBonusValue() const {
    return bonusValue;
}

float AttackBonus::getCollectionTime() const {
    return collectionTime;
}

float AttackBonus::getDuration() const {
    return duration;
}

//
// Created by federico on 29/09/19.
//

#include "Bonus.h"
#include "GameHero.h"

Bonus::Bonus(std::string &texturePath, int bonusV, float dur, int id) : Item(texturePath, id), bonusValue(bonusV),
                                                                        collectionTime(0.f), collected(false),
                                                                        duration(dur) {

    int attackBonusID = 43;
    int defenceBonusID = 45;

    attackType = id == attackBonusID;
}

void Bonus::interact(GameHero *player, Map &map) {

    collected = true;
    collectionTime = player->getClock().getElapsedTime().asSeconds();

    if (attackType)
        player->getWeapon()->setAttackBonus(this);
    else
        player->setDefenceBonus(this);


    for (int y = 0; y < map.getObjectsCollector().size(); y++) {
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
        }
    }

}

int Bonus::getBonusValue() const {
    return bonusValue;
}

float Bonus::getCollectionTime() const {
    return collectionTime;
}

float Bonus::getDuration() const {
    return duration;
}

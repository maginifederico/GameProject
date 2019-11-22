//
// Created by federico on 29/09/19.
//

#include "Bonus.h"
#include "GameHero.h"

Bonus::Bonus(std::string &texturePath, int bonusV, sf::Time dur, int id) : Item(texturePath, id), bonusValue(bonusV),
                                                                           collected(false), duration(dur) {

    int attackBonusID = 43;
    int defenceBonusID = 45;

    attackType = id == attackBonusID;
    getSprite().scale(0.137254902, 0.137254902);
}

void Bonus::interact(GameHero *player, Map &map) {

    collected = true;
    collectionTime = player->getClock().getElapsedTime();

    if (attackType)
        player->setAttackBonus(this);
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

sf::Time Bonus::getCollectionTime() const {
    return collectionTime;
}

sf::Time Bonus::getDuration() const {
    return duration;
}

//
// Created by sode on 27/09/19.
//

#include "AttackBonus.h"
#include "GameHero.h"

AttackBonus::AttackBonus(std::string &texturePath, int id, int bonus, float dur) : Item(texturePath, id, true),
                                                                                   bonus(bonus), collectionTime(0),
                                                                                   collected(false), duration(dur) {

}

void AttackBonus::interact(GameHero *player, Map &map) {


    toBeDrawn = false;
    collected = true;

    collectionTime = player->getClock().getElapsedTime().asSeconds();
    player->getWeapon()->setAttackBonus(this);


    for (int y = 0; y < map.getObjectsCollector().size(); y++) {
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
        }
    }
}

float AttackBonus::getDuration() const {
    return duration;
}

float AttackBonus::getCollectionTime() const {
    return collectionTime;
}

void AttackBonus::setDuration(float duration) {
    AttackBonus::duration = duration;
}

void AttackBonus::setCollectionTime(float collectionTime) {
    AttackBonus::collectionTime = collectionTime;
}

void AttackBonus::setCollected(bool collected) {
    AttackBonus::collected = collected;
}

int AttackBonus::getBonus() const {
    return bonus;
}

AttackBonus::~AttackBonus() = default;


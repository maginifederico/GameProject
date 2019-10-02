//
// Created by sode on 27/09/19.
//

#ifndef GAME_ATTACKBONUS_H
#define GAME_ATTACKBONUS_H

#include "Item.h"
#include "Map.h"

class GameHero;

class Item;

class AttackBonus : public Item {

public:

    AttackBonus(std::string &texturePath, int id, int bonus, float time);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override {};

    float getDuration() const;

    float getCollectionTime() const;

    void setDuration(float duration);

    void setCollectionTime(float collectionTime);

    void setCollected(bool collected);

    int getBonus() const;

    virtual ~AttackBonus();

private:

    int bonus;
    float duration;
    float collectionTime;
    bool collected;

};

#endif //GAME_ATTACKBONUS_H

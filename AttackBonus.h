//
// Created by federico on 29/09/19.
//

#ifndef GAME_ATTACKBONUS_H
#define GAME_ATTACKBONUS_H


#include "Map.h"
#include "Item.h"

//class Item;

class AttackBonus : public Item {

public:

    explicit AttackBonus(std::string &texturePath, int bonusValue, float duration, int id);

    void interact(GameHero *player, Map &map) override;

    int getBonusValue() const;

    float getCollectionTime() const;

    float getDuration() const;

//    void update(Map *map) override {};

//    float getDuration() const;
//
//    float getCollectionTime() const;
//
//    void setDuration(float duration);
//
//    void setCollectionTime(float collectionTime);
//
//    void setCollected(bool collected);
//
//    int getBonus() const;
//
//    virtual ~AttackBonus();

private:

    int bonusValue;
    float duration;
    float collectionTime;
    bool collected;
};


#endif //GAME_ATTACKBONUS_H

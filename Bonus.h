//
// Created by federico on 29/09/19.
//

#ifndef GAME_BONUS_H
#define GAME_BONUS_H


#include "Map.h"
#include "Item.h"

//class Item;

class Bonus : public Item {

public:

    explicit Bonus(std::string &texturePath, int bonusValue, float duration, int id);

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
//    virtual ~Bonus();

private:

    bool attackType;
    int bonusValue;
    float duration;
    float collectionTime;
    bool collected;
};


#endif //GAME_BONUS_H

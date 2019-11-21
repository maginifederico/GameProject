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

    explicit Bonus(std::string &texturePath, int bonusValue, sf::Time duration, int id);

    void interact(GameHero *player, Map &map) override;

    int getBonusValue() const;

    sf::Time getCollectionTime() const;

    sf::Time getDuration() const;

private:

    bool attackType;
    int bonusValue;
    sf::Time duration;
    sf::Time collectionTime;
    bool collected;
};


#endif //GAME_BONUS_H

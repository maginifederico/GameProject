//
// Created by federico on 30/09/19.
//

#ifndef GAME_DEFENCEBONUS_H
#define GAME_DEFENCEBONUS_H


#include "Item.h"

class DefenceBonus : public Item {

public:

    explicit DefenceBonus(std::string &texturePath, int bonusValue, float duration, int id);

    void interact(GameHero *player, Map &map) override;


};


#endif //GAME_DEFENCEBONUS_H

//
// Created by federico on 27/09/19.
//

#include "BlueFlag.h"

BlueFlag::BlueFlag(std::string &texturePath, int id) : Item(texturePath, id), animationNumber(0) {

    if (!animation1.loadFromFile(animationFlagPath1))
        std::cout << "Unable to load the sprite";

    if (!animation2.loadFromFile(animationFlagPath2))
        std::cout << "Unable to load the sprite";

}

void BlueFlag::interact(GameHero *player, Map &map) {

    map.setEndLevel(true);

}

void BlueFlag::update(Map *map) {

    if (clock.getElapsedTime().asSeconds() > animationSpeed) {
        if (animationNumber == 1) {

            getSprite().setTexture(animation2);
            animationNumber = 2;

        } else {

            getSprite().setTexture(animation1);
            animationNumber = 1;

        }

        clock.restart();

    }

}

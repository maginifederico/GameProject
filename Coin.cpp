//
// Created by federico on 19/09/19.
//

#include <iostream>
#include "Coin.h"

Coin::Coin(int cV, std::string &texturePath, int id) : Item(texturePath, id), coinValue(cV) {

//    if (!getTexture().loadFromFile(texturePath))
//        std::cout << "Unable to load the sprite";
//    getSprite().setTexture(getTexture());
}

//void Coin::interact() {
//
//    getSprite().move(10.f, 10.f);
//
//
//}

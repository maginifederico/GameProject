/**
 * Project Untitled
 */


#ifndef _ITEM_H
#define _ITEM_H

#include "Tile.h"

class Item {

public:
    void virtual interact() = 0;


private:

    int id;
    sf::FloatRect collision;
    sf::Sprite sprite;
    sf::Texture texture;

//    float posX;
//    float posY;
//    int coinValue;
//    int pillValue;
//    int shieldValue;
//    int attackValue;
//    float shieldTimer;
//    float attackTimer;

};

#endif //_ITEM_H
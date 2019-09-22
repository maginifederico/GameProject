/**
 * Project Untitled
 */


#ifndef _ITEM_H
#define _ITEM_H

#include "GameHero.h"

class Item {

public:
    explicit Item(std::string &texturePath, int id);

    virtual void interact(/*GUI gui,*/ GameHero *player, Map &map, int objectNumber) = 0;

    sf::Sprite &getSprite();

    sf::Texture &getTexture();

    const sf::FloatRect &getCollision() const;

    void setCollision(sf::FloatRect &collision);

    virtual void updateAnimation();

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
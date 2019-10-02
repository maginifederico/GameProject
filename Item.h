/**
 * Project Untitled
 */


#ifndef _ITEM_H
#define _ITEM_H

#include "Map.h"

class GameHero;
class Item {

public:
    explicit Item(std::string &texturePath, int id, bool toBeDrawn);

    virtual void interact(GameHero *player, Map &map) = 0;

    sf::Sprite &getSprite();

    sf::Texture &getTexture();

    const sf::FloatRect &getCollision() const;

    void setCollision(sf::FloatRect &collision);

    virtual void update(Map *map) {};

    int getId() const;

    bool isToBeDrawn() const;

protected:

    bool toBeDrawn;

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
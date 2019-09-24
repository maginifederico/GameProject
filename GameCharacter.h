/**
 * Project Untitled
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

class Map;

class GameCharacter {
public:

    GameCharacter(std::string &texture, sf::Vector2f initialPosition, float speed, float underWaterSpeed, int HP);

    virtual void setHP(int hp, Map &map) = 0;

    virtual void updatePosition(Map &map) = 0;

    virtual ~GameCharacter();

    sf::Sprite &getSprite();

    int getHp() const;



protected:
    int HP;
    float speed;
    float underWaterSpeed;

    sf::Texture texture;
    sf::Sprite sprite;

    virtual void die(Map &map) {};
};

#endif //_GAMECHARACTER_H
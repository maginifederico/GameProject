/**
 * Project Untitled
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

class GameCharacter {
public:

    GameCharacter(std::string texture, sf::Vector2f initialPosition, float speed);

    virtual void move() = 0;

    const sf::Sprite &getSprite() const;


protected:
    int HP;
    float speed;//FIXME togliere movement speed dal GameHero
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //_GAMECHARACTER_H
/**
 * Project Untitled
 */


#ifndef _FLYINGBEHAVIOUR_H
#define _FLYINGBEHAVIOUR_H

#include "MovementBehaviour.h"
#include "Map.h"


class FlyingBehaviour : public MovementBehaviour {

public:
    explicit FlyingBehaviour(bool dir = false);

    void updatePosition(Map &map, GameCharacter &enemy) override;

    void attack() override;

    void setPlayerPosition(const sf::Vector2f &playerPosition);

private:

    sf::Clock animationClock;
    const float animationTime = 0.16f;

    std::string animationSX[4];
    std::string animationDX[4];
    int animationNumber;

    sf::Texture textureSX[4];
    sf::Texture textureDX[4];

    sf::Vector2f playerPosition;

};

#endif //_FLYINGBEHAVIOUR_H
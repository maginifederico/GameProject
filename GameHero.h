/**
 * Project Untitled
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"


class GameHero : public GameCharacter {
public:

    sf::View playerView;

    void move() override;

    GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f playerView, float speed = 300.f);
//    Item *item;
//    Weapon *weapon;

private:
    sf::Vector2f velocity;
    const float jumpSpeed = -800.f;
    const float dt = 0.0003;
//    const float movementSpeed = 300.f;//FIXME spostare in GameCharacter nel campo speed?
    const float INITIAL_POSITION_X = 200.f;
    const float INITIAL_POSITION_Y = 300.f;//FIXME sposta in spawning point dopo aver fatto collisioni
    const float acceleration = -1.f;//FIXME sposta in mappa/fisica/CasettiCazzoLungoSpaccaGessetty
    sf::FloatRect playerBoundingBox;//FIXME
    bool isColliding;//FIXME

};

#endif //_GAMEHERO_H
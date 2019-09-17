/**
 * Project Untitled
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "Map.h"
#include "Weapon.h"
#include <list>


class Weapon;

class GameHero : public GameCharacter {


public:
    GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f playerView, Weapon *gun = nullptr,
             int HP = 100, float speed = 1.f, float underWaterSpeed = 0.5f);

    sf::View playerView;

    void updatePosition() override;

    void damage();

    std::unique_ptr<Weapon> getWeapon() const;
//    Weapon *getWeapon() const;

    void setWeapon(std::unique_ptr<Weapon> weapon);
//    void setWeapon(Weapon *weapon);

//    Item *item;
    Map *map;        //FIXME

    int getMovementDirection() const;

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

    void updateViewPosition();

private:

    //serve per vedere qual era l'ultima direzione posseduta dal giocatore. In questo modo si evita di ricaricare la
    //texture della patata quando la direzione non è cambiata. Vale true se era destra, false altrimenti.
    int movementDirection = true;

    sf::Vector2f velocity;
    const float jumpSpeed = -1.9f;
    const float jumpSpeedUnderWater = jumpSpeed / 4;
    sf::FloatRect viewPosition;

    std::unique_ptr<Weapon> weapon;
//    Weapon *weapon;
};


#endif //_GAMEHERO_H
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
             float speed = 1.f);

    sf::View playerView;

    void move() override;

    void damage();

    Weapon *getFrenchFries() const;

//    Item *item;
    Map *map;        //FIXME

    void setFrenchFries(Weapon *frenchFries);

    int getMovementDirection() const;

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

private:


    //serve per vedere qual era l'ultima direzione posseduta dal giocatore. In questo modo si evita di ricaricare la
    //texture della patata quando la direzione non è cambiata. Vale true se era destra, false altrimenti.
    int movementDirection = true;

    sf::Vector2f velocity;
    const float jumpSpeed = -1.9f;
    const float INITIAL_POSITION_X = 200.f;
    const float INITIAL_POSITION_Y = 300.f;//FIXME sposta in spawning point dopo aver fatto collisioni
    const float acceleration = -0.02f;//FIXME sposta in mappa/fisica
    const float waterAcceleration = -0.005f;//FIXME sposta in mappa/fisica
    sf::FloatRect viewPosition;


    //Creare vettore di weapons, per adesso c'è solo French Fries
    Weapon *frenchFries;

};

////OLD SETTINGS 1500 fps
//speed = 0.15f (nel costruttore, di default)
//const float jumpSpeed = -0.33f;
//const float INITIAL_POSITION_X = 200.f;
//const float INITIAL_POSITION_Y = 300.f;//FIXME sposta in spawning point dopo aver fatto collisioni
//const float acceleration = -0.0006f;//FIXME sposta in mappa/fisica
//const float waterAcceleration = -0.0001f;//FIXME sposta in mappa/fisica


#endif //_GAMEHERO_H
/**
 * Project Untitled
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "Map.h"


class GameHero : public GameCharacter {
public:

    sf::View playerView;

    void move() override;

    GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f playerView, float speed = 0.15f);
//    Item *item;
//    Weapon *weapon;
    Map *map;        //FIXME


private:


    //serve per vedere qual era l'ultima direzione posseduta dal giocatore. In questo modo si evita di ricaricare la
    //texture della patata quando la direzione non è cambiata. Vale true se era destra, false altrimenti.
    int movementDirection = true;

    sf::Vector2f velocity;
    const float jumpSpeed = -0.33f;
    const float INITIAL_POSITION_X = 200.f;
    const float INITIAL_POSITION_Y = 300.f;//FIXME sposta in spawning point dopo aver fatto collisioni
    const float acceleration = -0.0006f;//FIXME sposta in mappa/fisica
    const float waterAcceleration = -0.0001f;//FIXME sposta in mappa/fisica
    sf::FloatRect viewPosition;

    //attributo booleano che indica quando il player è entrato nell'acqua. Necessaria perchè al momento del
    //primo impatto con l'acqua è necessario impostare velocity.y a zero perchè sennò se ci si salta dentro, velocity.y
    //possiede ancora il valore che ha quando sta cadendo dall'aria, e waterAcceleration applica la gravità dell'acqua
    //ad un valore di velocity.y che non ha niente a che fare con l'acqua in quanto apparteneva alle condizioni in aria
    bool splash = false;

};

#endif //_GAMEHERO_H
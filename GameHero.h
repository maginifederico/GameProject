/**
 * Project Untitled
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "Weapon.h"
#include "Gui.h"
#include <list>


class Weapon;

class GameHero : public GameCharacter {


public:
    explicit GameHero(sf::Vector2f initialPosition, sf::Vector2f playerView, Weapon *gun = nullptr,
                      int HP = 100, float speed = 1.f, float underWaterSpeed = 0.5f,
                      std::string texture = "./Textures/PotatoDX.png");

    void updatePosition(Map &ground) override;

    Weapon *getWeapon() const;

    void setWeapon(std::unique_ptr<Weapon> weapon);

//    Item *item;

    int getMovementDirection() const;

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

    sf::Vector2f updateViewPosition(Map &map);

    void setWPressed(bool wPressed);

    void setAPressed(bool sPressed);

    void setSPressed(bool sPressed);

    void setDPressed(bool dPressed);

    void shoot();

    void checkCollection(Map &map);

    sf::View &getPlayerView();

//    void loadGui();
//
//    std::vector<sf::Text *> &getGuiText();
//
//    std::vector<sf::RectangleShape *> &getGuiShapes();

    Gui *getGui();

    void setHP(int hp, Map &map) override;

    bool isWPressed() const;

    int getShieldBonus() const;

    void setShieldBonus(int shieldBonus);

    const sf::Clock &getClock() const;

    void manageBonuses();

private:

    sf::Clock clock;

    void die(Map &map) override;


    //KEYBOARD WASD INPUTS
    bool W_Pressed;
    bool A_Pressed;
    bool S_Pressed;
    bool D_Pressed;


    //serve per vedere qual era l'ultima direzione posseduta dal giocatore. In questo modo si evita di ricaricare la
    //texture della patata quando la direzione non è cambiata. Vale true se era destra, false altrimenti.
    int movementDirection = true;


    sf::Vector2f velocity;
    const float jumpSpeed = -1.9f;
    const float jumpSpeedUnderWater = jumpSpeed / 4;
    sf::View playerView;
    sf::FloatRect viewPosition;
    int maxHP = 100;

    int shieldBonus;

    std::unique_ptr<Weapon> weapon;

    Gui *gui;
};


#endif //_GAMEHERO_H
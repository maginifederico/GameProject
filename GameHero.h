/**
 * Project Untitled
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "Weapon.h"
#include "Gui.h"
#include "Subject.h"
#include <list>


class Weapon;

class Bonus;

class Gui;

class GameHero : public GameCharacter, public Subject {


public:
    explicit GameHero(sf::Vector2f initialPosition, sf::Vector2f playerView, Gui &gui, Weapon *gun = nullptr,
                      int HP = 100,
                      float speed = 1.f, float underWaterSpeed = 0.5f, std::string texture = "./Textures/PotatoDX.png"
    );

    void updatePosition(Map &ground) override;

    Weapon *getWeapon() const;

    void setWeapon(std::unique_ptr<Weapon> weapon);

//    Item *item;

    Direction getMovementDirection() const;

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

    sf::Vector2f updateViewPosition(Map &map);

    void setWPressed(bool wPressed);

    void setAPressed(bool aPressed);

    void setSPressed(bool sPressed);

    void setDPressed(bool dPressed);

    void shoot();

    void checkCollection(Map &map);

    sf::View &getPlayerView();

    std::vector<sf::Text> &getGuiText();

    std::vector<sf::RectangleShape> &getGuiShapes();

    Gui &getGui();

    void setHP(int hp, Map &map) override;

    ~GameHero() {};

    const sf::Clock &getClock() const;

    void manageBonuses();

    void setDefenceBonus(Bonus *defenceBonus);

    void setAttackBonus(Bonus *atkBonus);

    Bonus *getDefenceBonus();

    void checkEnemyCollision(Map &map);

    void setGui(Gui &gui);

    bool isDead() const;

    void setDead(bool dead);

    void setLives(int lives);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

private:

    void die(Map &map) override;

    //KEYBOARD WASD INPUTS
    bool W_Pressed;
    bool A_Pressed;
    bool S_Pressed;
    bool D_Pressed;


    //serve per vedere qual era l'ultima direzione posseduta dal giocatore. In questo modo si evita di ricaricare la
    //texture della patata quando la direzione non è cambiata. Vale true se era destra, false altrimenti.
    Direction movementDirection;

    sf::Vector2f velocity;
    const float jumpSpeed = -1.9f;
    const float jumpSpeedUnderWater = jumpSpeed / 4;
    sf::View playerView;
    sf::FloatRect viewPosition;
    int maxHP = 100;
    int lives;
    bool dead;

    std::unique_ptr<Weapon> weapon;

    Gui &gui;

    sf::Clock clock;

    Bonus *defenceBonus;

    std::vector<Observer *> observers;


};


#endif //_GAMEHERO_H
//
// Created by sode on 21/09/19.
//

#ifndef GAME_GUI_H
#define GAME_GUI_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Observer.h"
#include "GameHero.h"

class GameHero;

class Gui : public Observer {
public:

    explicit Gui();

    void load(sf::View &playerView);

    void updatePosition(sf::Vector2f offset);

    std::vector<sf::RectangleShape> &getShapes();

    std::vector<sf::Text> &getText();

    void updateHealth(int HP);

    void setCoins(unsigned int coins);

    void updateCoinCount();

    void updateLivesCount(int lives);

    void updateAttackBonus();

    void updateDefenceBonus();

    void reset();

    void setSubject(GameHero *subject);

    unsigned int getCoins() const;

    void update() override;

private:

    std::vector<sf::RectangleShape> shapes;
    std::vector<sf::Text> text;

    int healthIndex = 2;
    int coinCountIndex = 0;
    int livesCountIndex = 2;

    bool attackBonusCollected;
    bool defenceBonusCollected;

    sf::Texture attackBonusTexture;
    sf::Texture defenceBonusTexture;
    sf::Texture transparent;

    unsigned int coins;

    GameHero *subject;

};

#endif //GAME_GUI_H

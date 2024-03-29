//
// Created by sode on 21/09/19.
//

#include <iostream>
#include "Gui.h"

Gui::Gui() : coins(0), attackBonusCollected(false), defenceBonusCollected(false), subject(nullptr) {

    if (!attackBonusTexture.loadFromFile("./Textures/AttackBonus.png"))
        std::cout << "Failed to load texture";

    if (!defenceBonusTexture.loadFromFile("./Textures/DefenceBonus.png"))
        std::cout << "Failed to load texture";

    if (!transparent.loadFromFile("./Textures/Transparent.png"))
        std::cout << "Failed to load texture";

}

void Gui::load(sf::View &playerView) {

    float barX = 30.f;
    float barY = 9.f;
    float healthX = 30.f;
    float healthY = 9.f;
    float healthIndicatorX = 5.f;
    float healthIndicatorY = 4.f;
    float coinIndicatorX = 5.f;
    float coinIndicatorY = 28.f;
    float coinNumberX = 31.f;
    float coinNumberY = 26.f;
    float livesX = 430.f;
    float livesY = 4.f;
    float livesCountX = 475.f;
    float livesCountY = 4.f;
    float attackBonusX = 5.f;
    float attackBonusY = 52.f;
    float defenceBonusX = 29.f;
    float defenceBonusY = 52.f;

    sf::Texture heart;
    sf::Texture coinTexture;

    if (!heart.loadFromFile("./Textures/HealthPill.png"))
        std::cout << "Unable to load heart shape";

    if (!coinTexture.loadFromFile("./Textures/Coin.png"))
        std::cout << "Unable to load coinTexture shape";

    sf::RectangleShape bar(sf::Vector2f(playerView.getSize().x / 10.f, playerView.getSize().y / 22.5f));
    bar.setOutlineThickness(1.f);
    bar.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Black);

    bar.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + barX,
                    playerView.getCenter().y - playerView.getSize().y / 2 + barY);

    sf::RectangleShape health(sf::Vector2f(playerView.getSize().x / 10.f, playerView.getSize().y / 22.5f));
    health.setFillColor(sf::Color::Green);
    health.setOutlineColor(sf::Color::Transparent);

    health.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + healthX,
                       playerView.getCenter().y - playerView.getSize().y / 2 + healthY);

    sf::RectangleShape healthIndicator(sf::Vector2f(22.f, 22.f));
    healthIndicator.setTexture(new sf::Texture(heart));

    healthIndicator.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + healthIndicatorX,
                                playerView.getCenter().y - playerView.getSize().y / 2 + healthIndicatorY);

    sf::RectangleShape coinIndicator(sf::Vector2f(22.f, 22.f));
    coinIndicator.setTexture(new sf::Texture(coinTexture));

    coinIndicator.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + coinIndicatorX,
                              playerView.getCenter().y - playerView.getSize().y / 2 + coinIndicatorY);

    sf::RectangleShape attackBonus(sf::Vector2f(22.f, 22.f));
    if (attackBonusCollected)
        attackBonus.setTexture(&attackBonusTexture, true);
    else
        attackBonus.setTexture(&transparent, true);
    attackBonus.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + attackBonusX,
                            playerView.getCenter().y - playerView.getSize().y / 2 + attackBonusY);


    sf::RectangleShape defenceBonus(sf::Vector2f(22.f, 22.f));
    if (defenceBonusCollected)
        defenceBonus.setTexture(&defenceBonusTexture, true);
    else
        defenceBonus.setTexture(&transparent, true);
    defenceBonus.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + defenceBonusX,
                             playerView.getCenter().y - playerView.getSize().y / 2 + defenceBonusY);

    sf::Text coinNumber;
    sf::Text lives;
    sf::Text livesCount;
    sf::Font font;

    if (!font.loadFromFile("./Fonts/ImperfectaRegular.ttf"))
        std::cout << "Error loading the font" << std::endl;


    coinNumber.setFont(*new sf::Font(font));
    coinNumber.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + coinNumberX,
                           playerView.getCenter().y - playerView.getSize().y / 2 + coinNumberY);
    coinNumber.setString(std::to_string(coins));
    coinNumber.setCharacterSize(21);
    coinNumber.setFillColor(sf::Color::Black);

    lives.setFont(*new sf::Font(font));
    lives.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + livesX,
                      playerView.getCenter().y - playerView.getSize().y / 2 + livesY);
    lives.setString("Lives:");
    lives.setCharacterSize(21);
    lives.setFillColor(sf::Color::Black);

    livesCount.setFont(*new sf::Font(font));
    livesCount.setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + livesCountX,
                           playerView.getCenter().y - playerView.getSize().y / 2 + livesCountY);
    livesCount.setString("3");
    livesCount.setCharacterSize(21);
    livesCount.setFillColor(sf::Color::Black);

    shapes.push_back(healthIndicator);
    shapes.push_back(bar);
    shapes.push_back(health);
    shapes.push_back(coinIndicator);
    shapes.push_back(attackBonus);
    shapes.push_back(defenceBonus);

    text.push_back(coinNumber);
    text.push_back(lives);
    text.push_back(livesCount);


}

void Gui::updatePosition(sf::Vector2f offset) {

    for (sf::RectangleShape &current : shapes)
        current.move(offset);


    for (sf::Text &current : text)
        current.move(offset);
}


std::vector<sf::RectangleShape> &Gui::getShapes() {
    return shapes;
}

std::vector<sf::Text> &Gui::getText() {
    return text;
}

void Gui::updateHealth() {

    shapes[healthIndex].setSize(
            sf::Vector2f(shapes[1].getSize().x * subject->getHp() / 100, shapes[healthIndex].getSize().y));

    switch (subject->getHp() / 33) {

        case 0: {
            shapes[healthIndex].setFillColor(sf::Color::Red);
            break;
        }

        case 1: {
            shapes[healthIndex].setFillColor(sf::Color::Yellow);
            break;
        }

        default:
            shapes[healthIndex].setFillColor(sf::Color::Green);

    }

}

void Gui::updateCoinCount() {

    text[coinCountIndex].setString(std::to_string(++coins));

}

void Gui::updateLivesCount(int lives) {

    text[livesCountIndex].setString(std::to_string(lives));

}

void Gui::reset() {

    text.clear();

    shapes.clear();

}

void Gui::update() {

    if (subject->getWeapon()->hasAttackBonus() != attackBonusCollected)
        updateAttackBonus();


    if (subject->hasDefenceBonus() != defenceBonusCollected)
        updateDefenceBonus();

    updateHealth();

    updateLivesCount(subject->getLives());
}

void Gui::updateAttackBonus() {

    if (attackBonusCollected) {
        attackBonusCollected = false;
        shapes[4].setTexture(&transparent, true);
    } else {
        attackBonusCollected = true;
        shapes[4].setTexture(&attackBonusTexture, true);
    }
}

void Gui::setSubject(GameHero *s) {
    subject = s;
}

void Gui::updateDefenceBonus() {

    if (defenceBonusCollected) {
        defenceBonusCollected = false;
        shapes[5].setTexture(&transparent, true);
    } else {
        defenceBonusCollected = true;
        shapes[5].setTexture(&defenceBonusTexture, true);

    }

}

void Gui::setCoins(unsigned int c) {

    Gui::coins = c;

}

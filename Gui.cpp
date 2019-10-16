//
// Created by sode on 21/09/19.
//

#include <iostream>
#include "Gui.h"

Gui::Gui() : coins(0) {


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


    auto *heart = new sf::Texture;
    auto *coinTexture = new sf::Texture;


    std::string healthPillPath = "./Textures/HealthPill.png";
    if (!heart->loadFromFile(healthPillPath))
        std::cout << "Unable to load heart shape";

    if (!coinTexture->loadFromFile("./Textures/Coin.png"))
        std::cout << "Unable to load coinTexture shape";

    sf::RectangleShape *bar = new sf::RectangleShape(
            sf::Vector2f(playerView.getSize().x / 10.f, playerView.getSize().y / 22.5f));
    bar->setOutlineThickness(1.f);
    bar->setOutlineColor(sf::Color::Black);
    bar->setFillColor(sf::Color::Black);

    bar->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + barX,
                     playerView.getCenter().y - playerView.getSize().y / 2 + barY);

    sf::RectangleShape *health = new sf::RectangleShape(
            sf::Vector2f(playerView.getSize().x / 10.f, playerView.getSize().y / 22.5f));
    health->setFillColor(sf::Color::Green);
    health->setOutlineColor(sf::Color::Transparent);

    health->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + healthX,
                        playerView.getCenter().y - playerView.getSize().y / 2 + healthY);

    sf::RectangleShape *healthIndicator = new sf::RectangleShape(sf::Vector2f(22.f, 22.f));
    healthIndicator->setTexture(heart);

    healthIndicator->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + healthIndicatorX,
                                 playerView.getCenter().y - playerView.getSize().y / 2 + healthIndicatorY);

    sf::RectangleShape *coinIndicator = new sf::RectangleShape(sf::Vector2f(22.f, 22.f));
    coinIndicator->setTexture(coinTexture);

    coinIndicator->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + coinIndicatorX,
                               playerView.getCenter().y - playerView.getSize().y / 2 + coinIndicatorY);

    auto *coinNumber = new sf::Text;
    auto *lives = new sf::Text;
    auto *livesCount = new sf::Text;
    auto *font = new sf::Font;

    if (!font->loadFromFile("./Fonts/ImperfectaRegular.ttf"))
        std::cout << "Error loading the font" << std::endl;

    coinNumber->setFont(*font);
    coinNumber->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + coinNumberX,
                            playerView.getCenter().y - playerView.getSize().y / 2 + coinNumberY);
    coinNumber->setString(std::to_string(coins));
    coinNumber->setCharacterSize(21);
    coinNumber->setFillColor(sf::Color::Black);

    lives->setFont(*font);
    lives->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + livesX,
                       playerView.getCenter().y - playerView.getSize().y / 2 + livesY);
    lives->setString("Lives:");
    lives->setCharacterSize(21);
    lives->setFillColor(sf::Color::Black);

    livesCount->setFont(*font);
    livesCount->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + livesCountX,
                            playerView.getCenter().y - playerView.getSize().y / 2 + livesCountY);
    livesCount->setString("3");
    livesCount->setCharacterSize(21);
    livesCount->setFillColor(sf::Color::Black);

    shapes.emplace_back(healthIndicator);
    shapes.emplace_back(bar);
    shapes.emplace_back(health);
    shapes.emplace_back(coinIndicator);

    text.emplace_back(coinNumber);
    text.emplace_back(lives);
    text.emplace_back(livesCount);



}

void Gui::updatePosition(sf::Vector2f offset) {

    for (sf::RectangleShape *current : shapes)
        current->move(offset);


    for (sf::Text *current : text)
        current->move(offset);
}

//void Gui::add(sf::RectangleShape *shape) {
//
//    shapes.emplace_back(shape);
//
//}

//void Gui::add(sf::Text *txt) {
//
//    text.emplace_back(txt);
//
//}

std::vector<sf::RectangleShape *> &Gui::getShapes() {
    return shapes;
}

std::vector<sf::Text *> &Gui::getText() {
    return text;
}

void Gui::updateHealth(int HP) {

    shapes[healthIndex]->setSize(sf::Vector2f(shapes[1]->getSize().x * HP / 100, shapes[healthIndex]->getSize().y));

    switch (HP / 33) {

        case 0: {
            shapes[healthIndex]->setFillColor(sf::Color::Red);
            break;
        }

        case 1: {
            shapes[healthIndex]->setFillColor(sf::Color::Yellow);
            break;
        }

        default:
            shapes[healthIndex]->setFillColor(sf::Color::Green);

    }

}

void Gui::updateCoinCount(int value) {

    coins += value;
    text[coinCountIndex]->setString(std::to_string(coins));

}

void Gui::updateLivesCount(int lives) {

    text[livesCountIndex]->setString(std::to_string(lives));

}

void Gui::reset() {

    for (sf::Text *txt : text)
        delete txt;
    text.clear();

    for (sf::RectangleShape *rect : shapes)
        delete rect;
    shapes.clear();

}
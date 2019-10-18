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


//    auto *heart = new sf::Texture;
//    auto *coinTexture = new sf::Texture;
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

//    auto *coinNumber = new sf::Text;
//    auto *lives = new sf::Text;
//    auto *livesCount = new sf::Text;
//    auto *font = new sf::Font;
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

void Gui::updateHealth(int HP) {

    shapes[healthIndex].setSize(sf::Vector2f(shapes[1].getSize().x * HP / 100, shapes[healthIndex].getSize().y));

    switch (HP / 33) {

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

void Gui::updateCoinCount(int value) {

    coins += value;
    text[coinCountIndex].setString(std::to_string(coins));

}

void Gui::updateLivesCount(int lives) {

    text[livesCountIndex].setString(std::to_string(lives));

}

void Gui::reset() {

//    for (sf::Text *txt : text)
//        delete txt;
    text.clear();

//    for (sf::RectangleShape *rect : shapes)
//        delete rect;
    shapes.clear();

}
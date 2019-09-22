//
// Created by sode on 21/09/19.
//

#include <iostream>
#include "Gui.h"

Gui::Gui(sf::View &playerView) {

    sf::Texture *heart = new sf::Texture;
    sf::Texture *coin = new sf::Texture;
    if (!heart->loadFromFile("./Textures/HealthPill.png"))
        std::cout << "Unable to load heart shape";

    if (!coin->loadFromFile("./Textures/Coin.png"))
        std::cout << "Unable to load coin shape";

    sf::RectangleShape *bar = new sf::RectangleShape(
            sf::Vector2f(playerView.getSize().x / 8.f, playerView.getSize().y / 15.f));
    bar->setOutlineThickness(2.f);
    bar->setOutlineColor(sf::Color::Black);
    bar->setFillColor(sf::Color::Black);

    bar->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + 40.f,
                     playerView.getCenter().y - playerView.getSize().y / 2 + 12.f);

    sf::RectangleShape *health = new sf::RectangleShape(
            sf::Vector2f(playerView.getSize().x / 8.f, playerView.getSize().y / 15.f));
    health->setFillColor(sf::Color::Green);
    health->setOutlineColor(sf::Color::Transparent);

    health->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + 40.f,
                        playerView.getCenter().y - playerView.getSize().y / 2 + 12.f);

    sf::RectangleShape *healthIndicator = new sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    healthIndicator->setTexture(heart);

    healthIndicator->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + 7.f,
                                 playerView.getCenter().y - playerView.getSize().y / 2 + 8.f);

    sf::RectangleShape *coinIndicator = new sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    coinIndicator->setTexture(coin);

    coinIndicator->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + 7.f,
                               playerView.getCenter().y - playerView.getSize().y / 2 + 40.f);

    sf::Text *txt = new sf::Text;
    sf::Font *font = new sf::Font;

    if (!font->loadFromFile("./Fonts/arial.ttf"))
        std::cout << "Error loading the font" << std::endl;

    txt->setFont(*font);
    txt->setPosition(playerView.getCenter().x - playerView.getSize().x / 2 + 40.f,
                     playerView.getCenter().y - playerView.getSize().y / 2 + 36.f);
    txt->setString("x00");
    txt->setCharacterSize(30);
    txt->setFillColor(sf::Color::Black);

    shapes.emplace_back(healthIndicator);
    shapes.emplace_back(bar);
    shapes.emplace_back(health);
    shapes.emplace_back(coinIndicator);

    text.emplace_back(txt);
//    sf::Texture test;
//    test.loadFromFile("./Textures/FrenchFriesWeapon.png");
//
//    sf::RectangleShape io (sf::Vector2f(30.f, 30.f));
//    io.setPosition(playerView.getCenter());
//    shapes.emplace_back(io);

}

void Gui::draw(sf::RenderWindow &window/*sf::Vector2f viewTopLeft, int HP*/) {

    for (sf::RectangleShape *current : shapes)
        window.draw(*current);


    for (sf::Text *current : text)
        window.draw(*current);


//    bar.setPosition(viewTopLeft.x - viewTopLeft.x / 2 + barX,
//                    viewTopLeft.y - viewTopLeft.y / 2 + barY);
//
//    health.setSize(sf::Vector2f(bar.getSize().x * (HP / 100.f), health.getSize().y)); //FIXME move to GameHero::takeDamage(); or Enemy::damage();
//
//    health.setPosition(viewTopLeft.x - viewTopLeft.x / 2 + healthX,
//                       viewTopLeft.y - viewTopLeft.y / 2 + healthY);
//
//    switch (HP / 33){
//
//        case 1: {
//            health.setFillColor(sf::Color::Yellow);
//            break;
//        }
//
//        case 0: {
//            health.setFillColor(sf::Color::Red);
//            break;
//        }
//
//        default:
//            health.setFillColor(sf::Color::Green);
//    }
//
//
//    healthIndicator.setPosition(viewTopLeft.x - viewTopLeft.x / 2 + healthIndicatorX, viewTopLeft.y - viewTopLeft.y / 2 + healthIndicatorY);
//
}

void Gui::updatePosition(sf::Vector2f offset) {

    for (sf::RectangleShape *current : shapes)
        current->move(offset);


    for (sf::Text *current : text)
        current->move(offset);
}

void Gui::add(sf::RectangleShape *shape) {

    shapes.emplace_back(shape);

}

void Gui::add(sf::Text *txt) {

    text.emplace_back(txt);

}

const std::vector<sf::RectangleShape *> &Gui::getShapes() const {
    return shapes;
}

const std::vector<sf::Text *> &Gui::getText() const {
    return text;
}


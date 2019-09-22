//
// Created by sode on 21/09/19.
//

#ifndef GAME_GUI_H
#define GAME_GUI_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Gui {
public:

    explicit Gui(sf::View &playerView);

    void draw(/*sf::Vector2f viewPosition, int HP*/sf::RenderWindow &window);

    void updatePosition(sf::Vector2f offset);

    void add(sf::Text *txt);

    void add(sf::RectangleShape *shape);

    const std::vector<sf::RectangleShape *> &getShapes() const;

    const std::vector<sf::Text *> &getText() const;

    void updateHealth(int HP);

    void updateCoinCount(int value);



private:

    std::vector<sf::RectangleShape *> shapes;
    std::vector<sf::Text *> text;

    int healthIndex = 2;
    int coinCountIndex = 0;


//    sf::RectangleShape bar;
//    sf::RectangleShape health;
//    sf::RectangleShape healthIndicator;
//    sf::RectangleShape coinIndicator;
//    sf::Text coinNumber;
//
//    float barX = 40.f;
//    float barY = 12.f;
//    float healthX = 40.f;
//    float healthY = 12.f;
//    float healthIndicatorX = 7.f;
//    float healthIndicatorY = 8.f;
//    float coinIndicatorX;
//    float coinIndicatorY;
//    float coinNumberX;
//    float coinNumberY;

};

#endif //GAME_GUI_H

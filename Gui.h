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

    explicit Gui();

    void load(sf::View &playerView);

    void updatePosition(sf::Vector2f offset);

    std::vector<sf::RectangleShape> &getShapes();

    std::vector<sf::Text> &getText();

    void updateHealth(int HP);

    void updateCoinCount(int value);

    void updateLivesCount(int lives);

    void reset();

    unsigned int getCoins() const;

private:

    std::vector<sf::RectangleShape> shapes;
    std::vector<sf::Text> text;

    int healthIndex = 2;
    int coinCountIndex = 0;
    int livesCountIndex = 2;

    unsigned int coins;

};

#endif //GAME_GUI_H

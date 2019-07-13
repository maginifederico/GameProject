#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Layer.h"
#include "GameHero.h"
#include "Map.h"


using namespace sf;

int main() {


    //TODO movimento view verticale
    //TODO collisioni con layer ground
    //TODO collisioni con layer oggetti
    //TODO implementare i bonus e monetine
    //TODO far sparare il giocatore
    //TODO creare nemici
    //TODO implementare salvataggio progressi

    //init game

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    const float VIEW_HEIGHT = 525.f;
    const float VIEW_WIDTH = 800.f;
    const std::string GAME_HERO_TEXTURE = "./Textures/singleBird.png";
    int i = 0;

    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");

    //player bounding box
//    bool isColliding = false;
//    FloatRect playerBoundingBox;
//
//    RectangleShape rectangleShape(Vector2f(50.f, 50.f));
//    rectangleShape.setFillColor(Color::Blue);
//    rectangleShape.setPosition(200.f,200.f);
//
//    FloatRect rect = rectangleShape.getGlobalBounds();
//    if (playerBoundingBox.intersects(rect)){
//        isColliding = true;
//        rectangleShape.setFillColor(Color::Red);
//        std::cout << "Collision" << std::endl;
//    }


    ////INIT MAP

    Map map(300, 25, "./Map/background.txt", "./Map/ground.txt");
    map.load();

//    // create the background layer from the level definition
//    Layer background_map;
//    if (!background_map.load(sf::Vector2u(21, 21), "./Map/background.txt"))
//
//        return -1;
//
//    // create the ground layer from the level definition
//    Layer ground_map;
//    if (!ground_map.load(sf::Vector2u(21, 21), "./Map/ground.txt"))
//        return -1;

    //init game elements
    ////INIT Player

    GameHero player(GAME_HERO_TEXTURE, Vector2f(map.getSpawnPoint().x, map.getSpawnPoint().y),
                    Vector2f(VIEW_WIDTH, VIEW_HEIGHT));



    ////GAME LOOP
    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //update input

//        playerBoundingBox = player.getSprite().getGlobalBounds();
//
//        if (playerBoundingBox.intersects(rect)){
//            isColliding = true;
//            rectangleShape.setFillColor(Color::Red);
//            std::cout << "Collision" << std::endl;
//        }

        player.move();

        //render
        window.clear();

        //render game elements
        window.draw(map.getLayer()[0]);
        window.draw(map.getLayer()[1]);
        window.draw(player.getSprite());
        window.setView(player.playerView);
//        window.draw(rectangleShape);

        //render ui
        window.display();
    }

    return 0;


}
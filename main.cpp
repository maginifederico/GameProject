#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Layer.h"
#include "GameHero.h"
#include "Map.h"


using namespace sf;

int main() {

    //TODO collisioni con layer ground
    //TODO collisioni con layer oggetti
    //TODO implementare i bonus e monetine

    //TODO movimento view verticale
    //TODO far sparare il giocatore
    //TODO creare nemici
    //TODO implementare salvataggio progressi

    //init game

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    const float VIEW_HEIGHT = 525.f;
    const float VIEW_WIDTH = 800.f;
    const std::string GAME_HERO_TEXTURE = "./Textures/patata_196x134.png";
    int i = 0;

    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(1500);


    ////INIT MAP

    //Background

    Texture backgroundTexture;
    Sprite background;

    if (!backgroundTexture.loadFromFile("./Textures/bground.png"))
        std::cout << "Unable to load the background";
    background.setTexture(backgroundTexture);
    background.setOrigin(0.f, 0.f);

    Map map(300, 25, "./Map/background.txt", "./Map/ground.txt");
    map.load();

    //init game elements

    ////INIT Player
    GameHero player(GAME_HERO_TEXTURE, Vector2f(map.getSpawnPoint().x, map.getSpawnPoint().y),
                    Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

    player.map = &map;



    ////GAME LOOP
    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //update input
        player.move();

        //render
        window.clear();



        //render game elements
        window.draw(background);
        window.draw(map.getLayer()[1]);
        window.draw(player.getSprite());
        window.setView(player.playerView);


        //render ui
        window.display();
    }

    return 0;


}
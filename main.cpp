#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Layer.h"
#include "GameHero.h"
#include "GameCharacter.h"
#include "Map.h"


using namespace sf;

int main() {

    ////FATTO
    //collisioni con layer ground
    //movimento nell'acqua
    //far sparare il giocatore
    //fps ridotto da 1500 a 160
    //collisione dei proiettili con layer ground


    ////DA RIVEDERE
    //TODO rivedere collisioni con layer ground (guardare i FIXME su GameHero)

    ////DA FARE
    //TODO Unit Testing
    //TODO collisioni con layer oggetti
    //TODO implementare i bonus e monetine
    //TODO movimento view verticale
    //TODO creare nemici
    //TODO implementare salvataggio progressi

    //init game

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    const float VIEW_HEIGHT = 525.f;
    const float VIEW_WIDTH = 800.f;
    const std::string GAME_HERO_TEXTURE = "./Textures/PotatoDX.png";

    ////FRENCH FRIES WEAPON SETTINGS
    std::string FRENCH_FRIES_TEXTURE = "./Textures/weaponFrenchFries.png";
    float french_fries_texture_scale = 0.08f;
    int french_fries_damage = 20;
    float french_fries_range = 400.f;
    float french_fries_cooldown = 0.2f;


    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(160);


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


    ////INIT PLAYER WEAPONS

    Weapon frenchFries(FRENCH_FRIES_TEXTURE, french_fries_texture_scale, french_fries_damage, french_fries_range,
                       french_fries_cooldown);


    //init game elements

    ////INIT Player
    GameHero player(GAME_HERO_TEXTURE, Vector2f(map.getSpawnPoint().x, map.getSpawnPoint().y),
                    Vector2f(VIEW_WIDTH, VIEW_HEIGHT)/*, frenchFries*/);
    player.setFrenchFries(&frenchFries);

    player.map = &map;


    //ERROR FIX
    Sprite sprite;
    Texture texture;

    if (!texture.loadFromFile("Textures/weaponFrenchFries.png"))
        std::cout << "error" << std::endl;

    sprite.setTexture(texture);


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
        player.getFrenchFries()->shoot(player.getFrenchFries(), player.getSprite().getPosition(),
                                       player.getMovementDirection());

        player.getFrenchFries()->projectileCollision(map.getLayer()[1]);


        //render
        window.clear();


        //render game elements
        window.draw(background);
        window.draw(map.getLayer()[1]);

        //FIXME Texture bianca
        for (Projectile projectile : player.getFrenchFries()->getProjectils()) {
            sprite = projectile.getSprite();
            sprite.setTexture(texture); //soluzione provvisoria
            window.draw(sprite);
        }
        window.draw(player.getSprite());
        window.setView(player.playerView);


        //render ui
        window.display();
    }

    return 0;


}
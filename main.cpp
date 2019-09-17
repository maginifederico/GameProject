#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Layer.h"
#include "GameHero.h"
#include "GameCharacter.h"
#include "Map.h"
#include "WeaponFactory.h"


using namespace sf;

int main() {

    ////FATTO
    //collisioni con layer ground
    //movimento nell'acqua
    //far sparare il giocatore
    //fps ridotto da 1500 a 160
    //collisione dei proiettili con layer ground
    //movimento view verticale
    //Factory per armi


    ////DA RIVEDERE
    //TODO rivedere collisioni con layer ground (guardare i FIXME su GameHero)

    ////DA FARE
    //TODO Unit Testing
    //TODO Factory per Map
    //TODO Caverna e Stanza Speciale in Liv.1
    //TODO smart pointer invece di row pointer
    //TODO gestione vita player e nemici con rettangolini rossi e verdi
    //TODO Observer per Achievements
    //TODO Menù principale
    //TODO State Pattern per stato gioco
    //TODO creare nemici
    //TODO Strategy per movimento nemici
    //TODO collisioni con layer oggetti
    //TODO implementare i bonus e monetine
    //TODO implementare potenziamenti
    //TODO implementare salvataggio progressi

    //init game

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    const float VIEW_HEIGHT = 300.f;
    const float VIEW_WIDTH = 500.f;
    const std::string GAME_HERO_TEXTURE = "./Textures/PotatoDX.png";

    ////FRENCH FRIES WEAPON SETTINGS
//    std::string FRENCH_FRIES_TEXTURE = "./Textures/justOne.png";
//    float french_fries_texture_scale = 0.08f;
//    int french_fries_damage = 20;
//    float french_fries_range = 400.f;
//    float french_fries_cooldown = 0.2f;

    ////LEVEL 1 SETTINGS
    float mapWidth = 6300.f;
    float mapHeight = 525.f;
    Vector2f spawnPoint(100.f, 300.f);


    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(160);


    ////INIT MAP


    //LOAD LEVEL 1
    Map map(mapWidth, mapHeight, spawnPoint, "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt",
            "./Map/objectsLevel1");
    map.load();

    //SETTA I LIMITI DELLA VIEW
    map.setViewLimits(VIEW_WIDTH, VIEW_HEIGHT);


    ////INIT PLAYER WEAPONS

    WeaponFactory weaponFactory;

    std::unique_ptr<Weapon> justOne = weaponFactory.createWeapon(0);

    std::unique_ptr<Weapon> frenchFries = weaponFactory.createWeapon(1);

//    Weapon *justOne = weaponFactory.createWeapon(0);

//    Weapon *frenchFries = weaponFactory.createWeapon(1);


//    Weapon frenchFries(FRENCH_FRIES_TEXTURE, french_fries_texture_scale, french_fries_damage, french_fries_range,
//                       french_fries_cooldown);


    //init game elements

    ////INIT Player
    GameHero player(GAME_HERO_TEXTURE, Vector2f(map.getSpawnPoint().x, map.getSpawnPoint().y),
                    Vector2f(VIEW_WIDTH, VIEW_HEIGHT)/*, weapon*/);
    player.setWeapon(justOne);

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
        player.updatePosition();
        player.updateViewPosition();
        player.getWeapon()->shoot(player.getSprite().getPosition(), player.getMovementDirection());

        player.getWeapon()->checkProjectileCollision(map.getLayer()[1]);


        //render
        window.clear();


        //render game elements
        window.draw(map.getLayer()[0]);
        window.draw(map.getLayer()[1]);
        window.draw(map.getLayer()[2]);
        //FIXME Texture bianca
        for (Projectile projectile : player.getWeapon()->getProjectils()) {
            window.draw(projectile.getSprite());
        }
        window.draw(player.getSprite());
        window.setView(player.playerView);


        //render ui
        window.display();
    }

    return 0;


}
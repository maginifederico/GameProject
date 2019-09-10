//
// Created by federico on 10/09/19.
//

#include "gtest/gtest.h"
#include "../GameHero.h"

TEST(GameHero, Constructor) {

    GameHero hero("./Textures/PotatoDX.png", sf::Vector2f(100.f, 0.f), sf::Vector2f(800.f, 525.f));

    ASSERT_EQ(100.f, hero.getSprite().getPosition().x);
    ASSERT_EQ(0.f, hero.getSprite().getPosition().y);
    ASSERT_TRUE(hero.getMovementDirection());

}

TEST(GameHero, Collision) {

    Map map(300, 25, "./Map/background.txt", "./Map/ground.txt");
    map.load();
    GameHero hero("./Textures/PotatoDX.png", sf::Vector2f(100.f, 0.f), sf::Vector2f(800.f, 525.f));
    hero.map = &map;


    //si posiziona il giocatore in terra in uno spigolo e si invoca il metodo move
    hero.getSprite().setPosition(336.f, 336.72f);
    hero.move();

    //velocity.y dev'essere zero, cioè il giocatore non deve essersi mosso verticalmente
    ASSERT_EQ(0, hero.getVelocity().y);

    //essendoci un ostacolo a destra, il movimento a destra dev'essere impedito, quindi il giocatore non deve cambiare posizione
    hero.setVelocity(sf::Vector2f(1.f, 0.f));
    hero.move();
    ASSERT_EQ(336.f, hero.getSprite().getPosition().x);

}

/**
 * Project Untitled
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */


GameHero::GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f view, float speed) : GameCharacter(
        texture,
        initialPosition, speed) {
    sprite.setScale(sf::Vector2f(0.15f, 0.15f));
    velocity.x = 0;
    velocity.y = 0;
    playerView.reset(sf::FloatRect(0, 0, view.x, view.y));
    isColliding = false;
}

void GameHero::move() {

    playerBoundingBox = this->getSprite().getGlobalBounds();

    velocity.x = 0;

//    dt = dtClock.restart().asSeconds();
//    dt = 0.0003f;


//// GESTIONE TASTI WASD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

        if (this->sprite.getPosition().y >= 300.f && velocity.y == 0.f) {//FIXME cambia 300 con collisione
            velocity.y = jumpSpeed * dt;
//            playerView.move(0.f,jumpSpeed * dt);//FIXME movimento view verticale
        }

    }

//        if (Keyboard::isKeyPressed(Keyboard::S)) {
//            velocity.y += speed * dt;
//
//        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x += -speed * dt;
        if (sprite.getPosition().x >= INITIAL_POSITION_X &&
            sprite.getPosition().x <= 6300.f - 3 * INITIAL_POSITION_X)//FIXME sostituire 6300 con MAP WIDTH
            playerView.move(-speed * dt, 0.f);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed * dt;
        if (sprite.getPosition().x >= INITIAL_POSITION_X &&
            sprite.getPosition().x <= 6300.f - (3 * INITIAL_POSITION_X))//FIXME sostituire 6300 con MAP WIDTH
            playerView.move(speed * dt, 0.f);

    }

    //Se il giocatore non è a terra, applica gravità
    if (sprite.getPosition().y < INITIAL_POSITION_Y) {
        velocity.y -= acceleration * dt;
    }

//    playerBoundingBox = sprite.getGlobalBounds();
//    if (!playerBoundingBox.intersects(rect))

    sprite.move(velocity);


    if (sprite.getPosition().y >= INITIAL_POSITION_Y) {//FIXME correggere con collisione
        velocity.y = 0;
    }


////  SCREEN COLLISION
//    left collision
    if (sprite.getPosition().x < 0.f)
        sprite.setPosition(0.f, sprite.getPosition().y);

    //top collision
    if (sprite.getPosition().y < 0.f)
        sprite.setPosition(sprite.getPosition().x, 0.f);

    //right collision
    if (sprite.getPosition().x + sprite.getGlobalBounds().width > 6300.f)//FIXME MAP_WIDTH 6300
        sprite.setPosition(6300.f - sprite.getGlobalBounds().width, sprite.getPosition().y);//FIXME MAP_WIDTH 6300

    //bottom collision
    if (sprite.getPosition().y + sprite.getGlobalBounds().height > 1010.f)//FIXME WINDOW HEIGHT 1010
        sprite.setPosition(sprite.getPosition().x, 1010.f - sprite.getGlobalBounds().height);//FIXME WINDOW HEIGHT 1010
}
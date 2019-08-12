/**
 * Project Untitled
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */


GameHero::GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f view, float speed) : GameCharacter(
        texture, initialPosition, speed) {
    sprite.setScale(sf::Vector2f(0.7142857f, 1.044776f));
    sprite.scale(0.15f, 0.15f);
    velocity.x = 0;
    velocity.y = 0;
    playerView.reset(sf::FloatRect(0, 0, view.x, view.y));
    isColliding = false;
    viewPosition.height = playerView.getSize().y;
    viewPosition.width = playerView.getSize().x;
    viewPosition.top = playerView.getCenter().y - playerView.getSize().y / 2;
    viewPosition.left = playerView.getCenter().x - playerView.getSize().x / 2;
}

void GameHero::move() {


    sf::Vector2f startingPosition(getSprite().getPosition());
    playerBoundingBox = getSprite().getGlobalBounds();
    horizontalCollision = 0;
    verticalCollision = 0;

    int c = sprite.getPosition().x / 21;
    int r = sprite.getPosition().y / 21;

    //TODO upper right

//    ricorda playerBoundingBox = sprite.getGlobalBounds();

    velocity.x = 0;

//    dt = dtClock.restart().asSeconds();
//    dt = 0.0003f;


//// GESTIONE TASTI WASD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if ((playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300].getCollision()) ||
             playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300 + 1].getCollision())) &&
            velocity.y == 0.f) {
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
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed * dt;
    }


    //Se il giocatore non è a terra, applica gravità
    if (!(playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300].getCollision()) ||
          playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300 + 1].getCollision())) ||
        (!playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300 + 1].getCollision()) &&
         playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300].getCollision()))) {
        velocity.y -= acceleration * dt;
    }

    sprite.move(velocity);


////  TILE COLLISION


    //DESTRA
    if (velocity.x > 0) {
        if (playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 1 + r * 300].getCollision()) //||
            /*playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 1 + r * 300 + 300].getCollision())*/) {
            sprite.setPosition(startingPosition.x, sprite.getPosition().y);
            horizontalCollision = 1;
            //sprite.setPosition(static_cast<int>(sprite.getPosition().x), sprite.getPosition().y);
        }
    }

    //SINISTRA
    if (velocity.x < 0) {
        if (playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300].getCollision()) ||
            (playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300 + 300].getCollision()) &&
             !playerBoundingBox.intersects(
                     map->getLayer()[1].getTile()[c + r * 300 + 300 + 1].getCollision()))) {//FIXME
//            velocity.x = 0;
            sprite.setPosition(startingPosition.x, sprite.getPosition().y);

            horizontalCollision = -1;
            //sprite.setPosition(static_cast<int>(sprite.getPosition().x), sprite.getPosition().y);
        }
    }

    //SOTTO
    if (velocity.y > 0) {
        //se non sta collidendo a sx e collide in basso a sx (se c'è uno spigolo a sx) e sta cadendo, allora collidi
        if (!playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300].getCollision()) &&
            playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300].getCollision()) //||
            /*playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300 + 1].getCollision())*/) {
            velocity.y = 0;
            verticalCollision = 1;
            //sprite.setPosition(sprite.getPosition().x, static_cast<int>(sprite.getPosition().y));
        }
        //se non sta collidendo a dx e collide in basso a dx (se c'è uno spigolo a dx) e sta cadendo, allora collidi
        if (!playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 1 + r * 300].getCollision()) &&
            playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + 300 + r * 300 + 1].getCollision())) {
            velocity.y = 0;
            verticalCollision = 1;
        }
    }

    //SOPRA
    if (velocity.y < 0) {
        //se non sta collidendo sopra a dx e collide a sx //oppure sta collidendo a dx e non collide a sx, non collidere, altrimenti
        if (!playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300 + 1].getCollision()) &&
            playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300].getCollision()));
        else {
            if (playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300].getCollision()) ||
                playerBoundingBox.intersects(map->getLayer()[1].getTile()[c + r * 300 + 1].getCollision())) {
                velocity.y = 0;
                verticalCollision = -1;
                //sprite.setPosition(sprite.getPosition().x, static_cast<int>(sprite.getPosition().y));

            }
        }
    }

//    sprite.move(velocity);

    if (sprite.getPosition().x >= INITIAL_POSITION_X && sprite.getPosition().x <= 6300.f - 3 * INITIAL_POSITION_X)
        playerView.move(getSprite().getPosition().x - startingPosition.x, 0.f);

//        playerView.move(velocity.x,0.f);

//    if (viewPosition.left >= 0 && viewPosition.top >= 0 && (viewPosition.top + viewPosition.height) <= 1010.f &&
//        (viewPosition.left + viewPosition.width) >=
//        6300.f)  ////&& sprite.getPosition().y >= INITIAL_POSITION_Y && sprite.getPosition().y <= map->getHeight()- INITIAL_POSITION_Y)
//        playerView.move(velocity);
//////    if (viewPosition.left > 0 && viewPosition.top > 0 && (viewPosition.top + viewPosition.height) > 1010.f &&
//////           (viewPosition.left + viewPosition.width) >6300.f)
//////
//    viewPosition.height = playerView.getSize().y;
//    viewPosition.width = playerView.getSize().x;
//    viewPosition.top = playerView.getCenter().y - playerView.getSize().y / 2;
//    viewPosition.left = playerView.getCenter().x - playerView.getSize().x / 2;

//    if (viewPosition.left > 0)
//        playerView.setCenter(0.f, playerView.getCenter().y);
//
//    if (viewPosition.top > 0)
//        playerView.setCenter(playerView.getCenter().x, 0.f);
//
//    if ((viewPosition.top + viewPosition.height) > 1010.f)
//        playerView.setCenter(playerView.getCenter().x, 1010.f - playerView.getSize().y / 2);
//
//    if ((viewPosition.left + viewPosition.width) > 6300.f)
//        playerView.setCenter((6300.f - playerView.getSize().x / 2), playerView.getCenter().y);



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
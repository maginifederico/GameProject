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
    viewPosition.height = playerView.getSize().y;
    viewPosition.width = playerView.getSize().x;
    viewPosition.top = playerView.getCenter().y - playerView.getSize().y / 2;
    viewPosition.left = playerView.getCenter().x - playerView.getSize().x / 2;
}

void GameHero::move() {

    sf::Vector2f startingPosition(getSprite().getPosition());

    int c = sprite.getPosition().x / 21;
    int r = sprite.getPosition().y / 21;

    int sinistra = map->getLayer()[1].getTile()[c + r * 300].getId();
    int destra = map->getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int sotto_sinistra = map->getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int sotto_destra = map->getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();

    velocity.x = 0;




//    ricorda playerBoundingBox = sprite.getGlobalBounds();


    ////APPLICAZIONE GRAVITA'
    //Se il giocatore non è a terra, applica gravità
    if ((sotto_sinistra == 0
         //e applica anche a meno che non ci sia uno spigolo a destra venendo dall' alto o da fermo sul terreno (cadendo -> velocity.y > 0)
         && !(sotto_destra != 0 && destra == 0 && velocity.y >= 0))
        //oppure anche se, venendo dall'alto o dal basso, si ha una parete a sx, altrimenti il giocatore si bloccava sul muro
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra != 0 && destra == 0 && velocity.y != 0)
        //oppure anche se, saltando, si ha uno spigolo a sx, sennò il giocatore si bloccava nel tile a dx dello spigolo a sx
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra == 0 && destra == 0 && velocity.y < 0)
        //oppure ci si trova in una situazione in cui si ha un muro a sx e un blocco sopra, altrimenti il giocatore si bloccava nell'angolino tra muro e blocco
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra != 0 && destra != 0)
        // FIXME il player entra nel muro nel tile più esterno degli spigoli se entra da sx per spigoli a sx o da dx per spigoli a dx, solo venendo dall'alto

            ) {
        velocity.y -= acceleration * dt; //applica gravità
    } else {
        velocity.y = 0; //ferma il movimento verticale del giocatore
    }


    //// GESTIONE TASTI WASD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if ((sotto_sinistra != 0 || sotto_destra != 0) && velocity.y == 0.f) {
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


    sprite.move(velocity);



////  TILE COLLISION

    ////DESTRA
    if (velocity.x > 0) {
        if (destra != 0
            // grazie alla condizione sotto il giocatore non entra più nel muro a dx nella parte più alta dello spigolo (se sta saltando)
            || (destra == 0 && sotto_destra != 0 && sotto_sinistra == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
        }
    }

    ////SINISTRA
    if (velocity.x < 0) {
        if (sinistra != 0
            || (sinistra == 0 && sotto_sinistra != 0 && sotto_destra == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
        }
    }

//    SOTTO
//    if (velocity.y > 0) {
//
//    }



    ////SOPRA
    if (velocity.y < 0) {
        if ((sinistra != 0 && sotto_sinistra == 0)
            || (destra != 0 && sotto_destra == 0)

                ) {
            velocity.y = 0;
        }
    }


    //MOVIMENTO VIEW
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
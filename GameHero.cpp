/**
 * Project Untitled
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */


GameHero::GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f view, Weapon *gun, float speed)
        : GameCharacter(
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
    movementDirection = true;
//    frenchFries = new Weapon(gun);
}

void GameHero::move() {

    sf::Vector2f startingPosition(getSprite().getPosition());

    int c = (int) sprite.getPosition().x / 21;
    int r = (int) sprite.getPosition().y / 21;

    int sinistra = map->getLayer()[1].getTile()[c + r * 300].getId();
    int destra = map->getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int sotto_sinistra = map->getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int sotto_destra = map->getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();

    int water = 47;
    int waterSurface = 48;
    int groundSurface = 31;
    int ground = 33;

    bool waterJump = false;


    velocity.x = 0;




//    ricorda playerBoundingBox = sprite.getGlobalBounds();

//    std::cout << "sinistra= " << sinistra << std::endl << "destra= " << destra << std::endl << "sotto_sinistra= "
//              << sotto_sinistra << std::endl << "sotto_destra= " << sotto_destra << std::endl
//              << "velocity.y= " << velocity.y << std::endl << std::endl;

    ////APPLICAZIONE GRAVITA'
    //Se il giocatore non è a terra e non c'è uno spigolo a destra venendo dall' alto o da fermo sul terreno (cadendo -> velocity.y > 0), applica gravità
    if ((sotto_sinistra == 0 && !(sotto_destra != 0 && destra == 0 && velocity.y >= 0))
        //oppure anche se, venendo dall'alto o dal basso, si ha una parete a sx, altrimenti il giocatore si bloccava sul muro
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra != 0 && destra == 0 && velocity.y != 0)
        //oppure anche se, saltando, si ha uno spigolo a sx, sennò il giocatore si bloccava nel tile a dx dello spigolo a sx
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra == 0 && destra == 0 && velocity.y < 0)
        //oppure ci si trova in una situazione in cui si ha un muro a sx e un blocco sopra, altrimenti il giocatore si bloccava nell'angolino tra muro e blocco
        || (sotto_sinistra != 0 && sotto_destra == 0 && sinistra != 0 && destra != 0)
        //oppure se si trova nell'acqua
        || (
                ////GESTIONE CONDIZIONE IN ACQUA
                (sotto_sinistra == waterSurface && sotto_destra == waterSurface)
                || (sotto_sinistra == water && sotto_destra == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= 525.f)
                || (sotto_destra == water && sinistra != water)
                || (sotto_sinistra == water && destra != 0 && sotto_destra != 0)


        )
        // FIXME il player entra nel muro nel tile più esterno degli spigoli se entra da sx per spigoli a sx o da dx per spigoli a dx, solo venendo dall'alto

        // FIXME problema uscita player dall'acqua

        // FIXME problema bloccaggio player in condizione sotto_sinistra = ground/groundSurface, sotto_destra = waterSurface, destra = aria e anche viceversa
        //  (quando si esce dall'acqua attaccati ad una parete si blocca il player)

        // FIXME problema spigolo di terra sotto l'acqua (ci si entra da sinistra)


            ) {

        if (
                (sotto_sinistra == waterSurface && sotto_destra == waterSurface)
                || (sotto_sinistra == water && sotto_destra == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= 525.f)
                || (sotto_destra == water && sinistra != water)
                || (sotto_sinistra == water && destra != 0 && sotto_destra != 0)


                ) {
            //se il player arriva troppo velocemente sull'acqua, fermalo
            if (velocity.y > 0.5 && sotto_sinistra == waterSurface && sotto_destra == waterSurface) {
                velocity.y = -waterAcceleration;
//                splash = true;
            }
            if (
                    ((sinistra == ground || sinistra == groundSurface) && sotto_sinistra == water)
                    || ((destra == ground || destra == groundSurface) && sotto_destra == water)
                    ) {
                waterJump = false;
            } else {
                waterJump = true;
            }
            velocity.y -= waterAcceleration; //applica gravità dell'acqua
        } else {
            velocity.y -= acceleration; //applica gravità
            waterJump = false;
        }

    } else {
        velocity.y = 0; //ferma il movimento verticale del giocatore
    }


    //// GESTIONE TASTI WASD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (((sotto_sinistra != 0 || sotto_destra != 0) && velocity.y == 0.f) || waterJump) {
            if (waterJump)
                velocity.y = jumpSpeed / 4;
            else
                velocity.y = jumpSpeed;

//            playerView.move(0.f,jumpSpeed * dt);//FIXME movimento view verticale
        }

    }

//        if (Keyboard::isKeyPressed(Keyboard::S)) {
//            velocity.y += speed * dt;
//
//        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        if (movementDirection) {
            if (!texture.loadFromFile("./Textures/PotatoSX.png"))
                std::cout << "Unable to load the sprite";
            sprite.setTexture(texture);
        }


        if (sinistra == water || sinistra == waterSurface) {
            velocity.x = -speed / 1.5;
        } else {
            velocity.x = -speed;
        }


        movementDirection = false;

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        if (!movementDirection) {
            if (!texture.loadFromFile("./Textures/PotatoDX.png"))
                std::cout << "Unable to load the sprite";
            sprite.setTexture(texture);
        }

        if (destra == water || destra == waterSurface) {
            velocity.x = speed / 2;
        } else {
            velocity.x = speed;
        }

        movementDirection = true;

    }

    sprite.move(velocity);



////  TILE COLLISION

    ////DESTRA
    if (velocity.x > 0) {
        if ((destra != 0 && destra != water && destra != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a dx nella parte più alta dello spigolo (se sta saltando)
            || (destra == 0 && sotto_destra != 0 && sotto_sinistra == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
        }
    }

    ////SINISTRA
    if (velocity.x < 0) {
        if ((sinistra != 0 && sinistra != water && sinistra != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a sx nella parte più alta dello spigolo (se sta saltando)
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
        //se sopra c'è un ostacolo, smetti di saltare e inizia a scendere
        if ((sinistra != 0 && sotto_sinistra == 0)
            || (destra != 0 && sotto_destra == 0)
            //oppure se ci si trova in acqua e c'è un ostacolo sopra
            || ((sinistra == ground || sinistra == groundSurface) && sotto_sinistra == water)
            || ((destra == ground || destra == groundSurface) && sotto_destra == water)
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
    if (sprite.getPosition().y + sprite.getGlobalBounds().height > 525.f)//FIXME WINDOW HEIGHT 1010
        sprite.setPosition(sprite.getPosition().x, 525.f - sprite.getGlobalBounds().height);//FIXME WINDOW HEIGHT 1010




}


void GameHero::damage() {

}

Weapon *GameHero::getFrenchFries() const {
    return frenchFries;
}

void GameHero::setFrenchFries(Weapon *frenchFries) {
    GameHero::frenchFries = frenchFries;
}

int GameHero::getMovementDirection() const {
    return movementDirection;
}
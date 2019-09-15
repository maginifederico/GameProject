/**
 * Project Untitled
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */


GameHero::GameHero(std::string texture, sf::Vector2f initialPosition, sf::Vector2f view, Weapon *gun, int HP,
                   float speed, float underWaterSpeed) : weapon(gun), map(nullptr),
                                                         GameCharacter(texture, initialPosition, speed, underWaterSpeed,
                                                                       HP) {
    sprite.setScale(sf::Vector2f(0.7142857f, 1.044776f));
    sprite.scale(0.15f, 0.15f);
    velocity.x = 0;
    velocity.y = 0;
    playerView.reset(sf::FloatRect(0.f, 100.f, view.x, view.y));
    viewPosition.height = playerView.getSize().y;
    viewPosition.width = playerView.getSize().x;
    viewPosition.top = playerView.getCenter().y - playerView.getSize().y / 2;
    viewPosition.left = playerView.getCenter().x - playerView.getSize().x / 2;
    movementDirection = true;
//    weapon = new Weapon(gun);
}

void GameHero::updatePosition() {

    sf::Vector2f startingPosition(getSprite().getPosition());

    int c = (int) sprite.getPosition().x / 21;
    int r = (int) sprite.getPosition().y / 21;

    int sinistra = map->getLayer()[1].getTile()[c + r * 300].getId();
    int destra = map->getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int sotto_sinistra = map->getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int sotto_destra = map->getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();


    int water = 48;
    int waterSurface = 49;
//    int groundSurface = 31;
    int groundSurface = 34;
//    int ground = 33;
    int ground = 36;
    int aria = 0;

    bool waterJump = false;


    velocity.x = 0;




//    ricorda playerBoundingBox = sprite.getGlobalBounds();

//    std::cout << "sinistra= " << sinistra << std::endl << "destra= " << destra << std::endl << "sotto_sinistra= "
//              << sotto_sinistra << std::endl << "sotto_destra= " << sotto_destra << std::endl
//              << "velocity.y= " << velocity.y << std::endl << std::endl;

//    std::cout << getSprite().getPosition().x << std::endl << getSprite().getPosition().y << std::endl << std::endl;

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
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map->getHeight())
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
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map->getHeight())
                || (sotto_destra == water && sinistra != water)
                || (sotto_sinistra == water && destra != 0 && sotto_destra != 0)


                ) {
            //se il player arriva troppo velocemente sull'acqua, fermalo
            if (velocity.y > 0.5 && sotto_sinistra == waterSurface && sotto_destra == waterSurface) {
                velocity.y = -map->getWaterAcceleration();
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
            velocity.y -= map->getWaterAcceleration(); //applica gravità dell'acqua
        } else {
            velocity.y -= map->getAcceleration(); //applica gravità
            waterJump = false;
        }

    } else {
        velocity.y = 0; //ferma il movimento verticale del giocatore
    }


    //// GESTIONE TASTI WASD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (((sotto_sinistra != 0 || sotto_destra != 0) && velocity.y == 0.f) || waterJump) {
            if (waterJump)
                velocity.y = jumpSpeedUnderWater;
            else
                velocity.y = jumpSpeed;

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
            velocity.x = -underWaterSpeed;
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
            velocity.x = underWaterSpeed;
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
            velocity.x = 0;
        }
    }

    ////SINISTRA
    if (velocity.x < 0) {
        if ((sinistra != 0 && sinistra != water && sinistra != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a sx nella parte più alta dello spigolo (se sta saltando)
            || (sinistra == 0 && sotto_sinistra != 0 && sotto_destra == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
            velocity.x = 0;
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



////  SCREEN COLLISION
    //left collision
    if (sprite.getPosition().x < 0.f)
        sprite.setPosition(0.f, sprite.getPosition().y);

    //top collision
    if (sprite.getPosition().y < 0.f)
        sprite.setPosition(sprite.getPosition().x, 0.f);

    //right collision
    if (sprite.getPosition().x + sprite.getGlobalBounds().width > map->getWidth())
        sprite.setPosition(map->getWidth() - sprite.getGlobalBounds().width, sprite.getPosition().y);

    //bottom collision
    if (sprite.getPosition().y + sprite.getGlobalBounds().height > map->getHeight())
        sprite.setPosition(sprite.getPosition().x, map->getHeight() - sprite.getGlobalBounds().height);


//    std::cout << "Velocity.y= " << velocity.y << std::endl;

}


void GameHero::updateViewPosition() {

    ////MOVIMENTO VIEW

    //Orizzontale
    if (sprite.getPosition().x >= map->getViewHorizontalLimitSx() &&
        sprite.getPosition().x <= map->getViewHorizontalLimitDx())
        playerView.move(velocity.x, 0.f);



    //Verticale
    if (
        //Queste due condizioni impediscono il movimento della view oltre i limiti della mappa. Il centro della
        //view è sempre compreso tra il limite superiore e inferiore
            playerView.getCenter().y + velocity.y >= map->getViewVerticalLimitUp()
            && (playerView.getCenter().y + velocity.y <= map->getViewVerticalLimitDown())
            && (sprite.getPosition().y - playerView.getCenter().y >
                50.f /*|| sprite.getPosition().y - playerView.getCenter().y < - 100.f*/)

            ) {

        playerView.move(0.f, velocity.y);

    }

//        playerView.updatePosition(velocity.x,0.f);

//    if (viewPosition.left >= 0 && viewPosition.top >= 0 && (viewPosition.top + viewPosition.height) <= 1010.f &&
//        (viewPosition.left + viewPosition.width) >=
//        6300.f)  ////&& sprite.getPosition().y >= INITIAL_POSITION_Y && sprite.getPosition().y <= map->getHeight()- INITIAL_POSITION_Y)
//        playerView.updatePosition(velocity);
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



}

void GameHero::damage() {

}

Weapon *GameHero::getWeapon() const {
    return weapon;
}

void GameHero::setWeapon(Weapon *frenchFries) {
    GameHero::weapon = frenchFries;
}

int GameHero::getMovementDirection() const {
    return movementDirection;
}

const sf::Vector2f &GameHero::getVelocity() const {
    return velocity;
}

void GameHero::setVelocity(const sf::Vector2f &velocity) {
    GameHero::velocity = velocity;
}

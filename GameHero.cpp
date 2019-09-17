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

    int c = (int) sprite.getPosition().x / 21;
    int r = (int) sprite.getPosition().y / 21;

    int left = map->getLayer()[1].getTile()[c + r * 300].getId();
    int right = map->getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int down_left = map->getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int down_right = map->getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();


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

//    std::cout << "left= " << left << std::endl << "right= " << right << std::endl << "down_left= "
//              << down_left << std::endl << "down_right= " << down_right << std::endl
//              << "velocity.y= " << velocity.y << std::endl << std::endl;

//    std::cout << getSprite().getPosition().x << std::endl << getSprite().getPosition().y << std::endl << std::endl;

    ////APPLICAZIONE GRAVITA'
    //Se il giocatore non è a terra e non c'è uno spigolo a right venendo dall' alto o da fermo sul terreno (cadendo -> velocity.y > 0), applica gravità
    if ((down_left == 0 && !(down_right != 0 && right == 0 && velocity.y >= 0))
        //oppure anche se, venendo dall'alto o dal basso, si ha una parete a sx, altrimenti il giocatore si bloccava sul muro
        || (down_left != 0 && down_right == 0 && left != 0 && right == 0 && velocity.y != 0)
        //oppure anche se, saltando, si ha uno spigolo a sx, sennò il giocatore si bloccava nel tile a dx dello spigolo a sx
        || (down_left != 0 && down_right == 0 && left == 0 && right == 0 && velocity.y < 0)
        //oppure ci si trova in una situazione in cui si ha un muro a sx e un blocco sopra, altrimenti il giocatore si bloccava nell'angolino tra muro e blocco
        || (down_left != 0 && down_right == 0 && left != 0 && right != 0)
        //oppure se si trova nell'acqua
        || (
                ////GESTIONE CONDIZIONE IN ACQUA
                (down_left == waterSurface && down_right == waterSurface)
                || (down_left == water && down_right == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map->getHeight())
                || (down_right == water && left != water)
                || (down_left == water && right != 0 && down_right != 0)


        )
        // FIXME il player entra nel muro nel tile più esterno degli spigoli se entra da sx per spigoli a sx o da dx per spigoli a dx, solo venendo dall'alto

        // FIXME problema uscita player dall'acqua

        // FIXME problema bloccaggio player in condizione down_left = ground/groundSurface, down_right = waterSurface, right = aria e anche viceversa
        //  (quando si esce dall'acqua attaccati ad una parete si blocca il player)

        // FIXME problema spigolo di terra sotto l'acqua (ci si entra da left)


            ) {

        if (
            //Se il giocatore è nell'acqua
                (down_left == waterSurface && down_right == waterSurface)
                || (down_left == water && down_right == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map->getHeight())
                || (down_right == water && left != water)
                || (down_left == water && right != 0 && down_right != 0)


                ) {
            //se il player arriva troppo velocemente sull'acqua, fermalo
            if (velocity.y > 0.5 && down_left == waterSurface && down_right == waterSurface) {
                velocity.y = -map->getWaterAcceleration();
            }
            if (
                    ((left == ground || left == groundSurface) && down_left == water)
                    || ((right == ground || right == groundSurface) && down_right == water)
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
        if (((down_left != 0 || down_right != 0) && velocity.y == 0.f) || waterJump) {
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


        if (left == water || left == waterSurface) {
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

        if (right == water || right == waterSurface) {
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
        if ((right != 0 && right != water && right != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a dx nella parte più alta dello spigolo (se sta saltando)
            || (right == 0 && down_right != 0 && down_left == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
            velocity.x = 0;
        }
    }

    ////SINISTRA
    if (velocity.x < 0) {
        if ((left != 0 && left != water && left != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a sx nella parte più alta dello spigolo (se sta saltando)
            || (left == 0 && down_left != 0 && down_right == 0 && velocity.y != 0)
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
        if ((left != 0 && down_left == 0)
            || (right != 0 && down_right == 0)
            //oppure se ci si trova in acqua e c'è un ostacolo sopra
            || ((left == ground || left == groundSurface) && down_left == water)
            || ((right == ground || right == groundSurface) && down_right == water)
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
//    std::cout << "Center= " << playerView.getCenter().x << std::endl << playerView.getCenter().y << std::endl;
//    std::cout << getSprite().getPosition().x << std::endl << getSprite().getPosition().y << std::endl << std::endl;


}


void GameHero::updateViewPosition() {

    ////MOVIMENTO VIEW

    //Orizzontale
    if (sprite.getPosition().x >= map->getViewHorizontalLimitSx() &&
        sprite.getPosition().x <= map->getViewHorizontalLimitDx())
        playerView.move(velocity.x, 0.f);


    float defaultDistanceY = 40.f;
    //Verticale
    if (
        //Queste due condizioni impediscono il movimento della view oltre i limiti della mappa. Il centro della
        //view è sempre compreso tra il limite superiore e inferiore
//            playerView.getCenter().y + velocity.y >= map->getViewVerticalLimitUp()
//            && (playerView.getCenter().y + velocity.y <= map->getViewVerticalLimitDown())
            sprite.getPosition().y - defaultDistanceY >= map->getViewVerticalLimitUp()
            && sprite.getPosition().y - defaultDistanceY <= map->getViewVerticalLimitDown()
            && playerView.getCenter().y - sprite.getPosition().y != -defaultDistanceY

            ) {

        playerView.setCenter(playerView.getCenter().x, sprite.getPosition().y - defaultDistanceY);
//        playerView.move(0.f, velocity.y);

    }


}

void GameHero::damage() {

}

//std::unique_ptr<Weapon>GameHero::getWeapon() const {
//    return weapon;
//}
Weapon *GameHero::getWeapon() const {
    return weapon;
}

void GameHero::setWeapon(Weapon *weapon) {
    GameHero::weapon = weapon;
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

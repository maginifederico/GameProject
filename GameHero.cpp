/**
 * Project Untitled
 */


#include "GameHero.h"
#include "Map.h"
#include "Weapon.h"


/**
 * GameHero implementation
 */


GameHero::GameHero(sf::Vector2f initialPosition, sf::Vector2f view, Weapon *gun, int HP,
                   float speed, float underWaterSpeed, std::string texture) : weapon(gun), lives(3),
                                                                              GameCharacter(texture, initialPosition,
                                                                                            speed, underWaterSpeed,
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
    movementDirection = right;
    W_Pressed = false;
    A_Pressed = false;
    S_Pressed = false;
    D_Pressed = false;
    gui = new Gui();
    defenceBonus = nullptr;
//    weapon = new Weapon(gun);
}

void GameHero::updatePosition(Map &map) {
    int c = (int) sprite.getPosition().x / 21;
    int r = (int) sprite.getPosition().y / 21;
    int leftTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21)].getId();
    int rightTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1].getId();
    int downLeftTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + int(map.getWidth() / 21)].getId();
    int downRightTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + int(map.getWidth() / 21) +
                                                 1].getId();
    int water = 48;
    int waterSurface = 49;
    int groundSurface = 34;
    int ground1 = 36;
    int ground2 = 40;
    int ground3 = 139;
    int aria = 0;
    bool waterJump = false;
    velocity.x = 0;
//    std::cout << "leftTile= " << leftTile << std::endl << "rightTile= " << rightTile << std::endl << "downLeftTile= "
//              << downLeftTile << std::endl << "downRightTile= " << downRightTile << std::endl
//              << "velocity.y= " << velocity.y << std::endl << std::endl;

//    std::cout << getSprite().getPosition().x << std::endl << getSprite().getPosition().y << std::endl << std::endl;

    ////APPLICAZIONE GRAVITA'
    //Se il giocatore non è a terra e non c'è uno spigolo a rightTile venendo dall' alto o da fermo sul terreno (cadendo -> velocity.y > 0), applica gravità
    if ((downLeftTile == 0 && !(downRightTile != 0 && rightTile == 0 && velocity.y >= 0))
        //oppure anche se, venendo dall'alto o dal basso, si ha una parete a sx, altrimenti il giocatore si bloccava sul muro
        || (downLeftTile != 0 && downRightTile == 0 && leftTile != 0 && rightTile == 0 && velocity.y != 0)
        //oppure anche se, saltando, si ha uno spigolo a sx, sennò il giocatore si bloccava nel tile a dx dello spigolo a sx
        || (downLeftTile != 0 && downRightTile == 0 && leftTile == 0 && rightTile == 0 && velocity.y < 0)
        //oppure ci si trova in una situazione in cui si ha un muro a sx e un blocco sopra, altrimenti il giocatore si bloccava nell'angolino tra muro e blocco
        || (downLeftTile != 0 && downRightTile == 0 && leftTile != 0 && rightTile != 0)
        //oppure se si trova nell'acqua
        || (
                ////GESTIONE CONDIZIONE IN ACQUA
                (downLeftTile == waterSurface && downRightTile == waterSurface)
                || (downLeftTile == water && downRightTile == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map.getHeight())
                || (downRightTile == water && leftTile != water)
                || (downLeftTile == water && rightTile != 0 && downRightTile != 0)
        )
        // FIXME il player entra nel muro nel tile più esterno degli spigoli se entra da sx per spigoli a sx o da dx per spigoli a dx, solo venendo dall'alto
        // FIXME problema uscita player dall'acqua
        // FIXME problema bloccaggio player in condizione downLeftTile = ground/groundSurface, downRightTile = waterSurface, rightTile = aria e anche viceversa
        //  (quando si esce dall'acqua attaccati ad una parete si blocca il player)
        // FIXME problema spigolo di terra sotto l'acqua (ci si entra da leftTile)
            ) {
        if (
            //Se il giocatore è nell'acqua
                (downLeftTile == waterSurface && downRightTile == waterSurface)
                || (downLeftTile == water && downRightTile == water)
                || (sprite.getPosition().y + sprite.getGlobalBounds().height >= map.getHeight())
                || (downRightTile == water && leftTile != water)
                || (downLeftTile == water && rightTile != 0 && downRightTile != 0)
                ) {
            //se il player arriva troppo velocemente sull'acqua, fermalo
            if (velocity.y > 0.5 && downLeftTile == waterSurface && downRightTile == waterSurface) {
                velocity.y = -map.getWaterAcceleration();
            }
            if (
                    (((leftTile == ground1 || leftTile == ground2 || leftTile == ground3) ||
                      leftTile == groundSurface) &&
                     downLeftTile == water)
                    || (((rightTile == ground1 || rightTile == ground2 || rightTile == ground3) ||
                         rightTile == groundSurface) &&
                        downRightTile == water)
                    ) {
                waterJump = false;
            } else {
                waterJump = true;
            }
            velocity.y -= map.getWaterAcceleration(); //applica gravità dell'acqua
        } else {
            velocity.y -= map.getAcceleration(); //applica gravità
            waterJump = false;
        }
    } else {
        velocity.y = 0; //ferma il movimento verticale del giocatore
    }
    //// GESTIONE TASTI WASD
    if (W_Pressed) {
        if (((downLeftTile != 0 || downRightTile != 0) && velocity.y == 0.f) || waterJump) {
            if (waterJump)
                velocity.y = jumpSpeedUnderWater;
            else
                velocity.y = jumpSpeed;
        }
    }
//        if (S_Pressed)) {
//            velocity.y += speed * dt;
//
//        }

    if (A_Pressed) {
        if (movementDirection == right) {
            if (!texture.loadFromFile("./Textures/PotatoSX.png"))
                std::cout << "Unable to load the sprite";
            sprite.setTexture(texture);
        }
        if (leftTile == water || leftTile == waterSurface) {
            velocity.x = -underWaterSpeed;
        } else {
            velocity.x = -speed;
        }
        movementDirection = left;
    }
    if (D_Pressed) {
        if (movementDirection == left) {
            if (!texture.loadFromFile("./Textures/PotatoDX.png"))
                std::cout << "Unable to load the sprite";
            sprite.setTexture(texture);
        }
        if (rightTile == water || rightTile == waterSurface) {
            velocity.x = underWaterSpeed;
        } else {
            velocity.x = speed;
        }
        movementDirection = right;
    }
    sprite.move(velocity);
////  TILE COLLISION

    ////DESTRA
    if (velocity.x > 0) {
        if ((rightTile != 0 && rightTile != water && rightTile != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a dx nella parte più alta dello spigolo (se sta saltando)
            || (rightTile == 0 && downRightTile != 0 && downLeftTile == 0 && velocity.y != 0)
                ) {
            sprite.move(-velocity.x, 0);
            velocity.x = 0;
        }
    }
    ////SINISTRA
    if (velocity.x < 0) {
        if ((leftTile != 0 && leftTile != water && leftTile != waterSurface)
            // grazie alla condizione sotto il giocatore non entra più nel muro a sx nella parte più alta dello spigolo (se sta saltando)
            || (leftTile == 0 && downLeftTile != 0 && downRightTile == 0 && velocity.y != 0)
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
        if ((leftTile != 0 && downLeftTile == 0)
            || (rightTile != 0 && downRightTile == 0)
            //oppure se ci si trova in acqua e c'è un ostacolo sopra
            ||
            (((leftTile == ground1 || leftTile == ground2 || leftTile == ground3) || leftTile == groundSurface) &&
             downLeftTile == water)
            ||
            (((rightTile == ground1 || rightTile == ground2 || rightTile == ground3) || rightTile == groundSurface) &&
             downRightTile == water)
                ) {
            velocity.y = 0;
        }
    }
////  SCREEN COLLISION
    //leftTile collision
    if (sprite.getPosition().x < 0.f)
        sprite.setPosition(0.f, sprite.getPosition().y);
    //top collision
    if (sprite.getPosition().y < 0.f)
        sprite.setPosition(sprite.getPosition().x, 0.f);
    //rightTile collision
    if (sprite.getPosition().x + sprite.getGlobalBounds().width > map.getWidth())
        sprite.setPosition(map.getWidth() - sprite.getGlobalBounds().width, sprite.getPosition().y);
    //bottom collision
    if (sprite.getPosition().y + sprite.getGlobalBounds().height > map.getHeight())
        sprite.setPosition(sprite.getPosition().x, map.getHeight() - sprite.getGlobalBounds().height);
    W_Pressed = false;
    A_Pressed = false;
    S_Pressed = false;
    D_Pressed = false;
//    std::cout << "Velocity.y= " << velocity.y << std::endl;
//    std::cout << "Center= " << playerView.getCenter().x << std::endl << playerView.getCenter().y << std::endl;
//    std::cout << getSprite().getPosition().x << std::endl << getSprite().getPosition().y << std::endl << std::endl;


}


sf::Vector2f GameHero::updateViewPosition(Map &map) {
    sf::Vector2f offset(0.f, 0.f);
    ////MOVIMENTO VIEW
    //Orizzontale
    if (sprite.getPosition().x >= map.getViewHorizontalLimitSx() &&
        sprite.getPosition().x <= map.getViewHorizontalLimitDx()) {
        playerView.move(velocity.x, 0.f);
        offset.x = velocity.x;
    }
    float defaultDistanceY = 40.f;
    //Verticale
    if (
        //Queste due condizioni impediscono il movimento della view oltre i limiti della mappa. Il centro della
        //view è sempre compreso tra il limite superiore e inferiore
            sprite.getPosition().y - defaultDistanceY >= map.getViewVerticalLimitUp()
            && sprite.getPosition().y - defaultDistanceY <= map.getViewVerticalLimitDown()
            && playerView.getCenter().y - sprite.getPosition().y != -defaultDistanceY
            ) {
        offset.y -= playerView.getCenter().y;
        playerView.setCenter(playerView.getCenter().x, sprite.getPosition().y - defaultDistanceY);
        offset.y += playerView.getCenter().y;
    }
    gui->updatePosition(offset);
    return offset;
}


Weapon *GameHero::getWeapon() const {
    return weapon.get();
}


void GameHero::setWeapon(std::unique_ptr<Weapon> w) {
    GameHero::weapon = std::move(w);
}


Direction GameHero::getMovementDirection() const {
    return movementDirection;
}

const sf::Vector2f &GameHero::getVelocity() const {
    return velocity;
}

void GameHero::setVelocity(const sf::Vector2f &vel) {
    GameHero::velocity = vel;
}

void GameHero::setWPressed(bool wPressed) {
    W_Pressed = wPressed;
}

void GameHero::setAPressed(bool aPressed) {
    A_Pressed = aPressed;
}

void GameHero::setSPressed(bool sPressed) {
    S_Pressed = sPressed;
}

void GameHero::setDPressed(bool dPressed) {
    D_Pressed = dPressed;
}

void GameHero::shoot() {
    weapon->createProjectile(getSprite().getPosition(), movementDirection);
}

void GameHero::checkCollection(Map &map) {
    for (int i = 0; i < map.getObjectsCollector().size(); i++) {
        if (sprite.getGlobalBounds().intersects(map.getObjectsCollector()[i]->getCollision())) {
            map.getObjectsCollector()[i]->interact(this, map);
        }
    }
}

sf::View &GameHero::getPlayerView() {
    return playerView;
}

void GameHero::die(Map &map) {
    if (--lives < 0) {
        //TODO torna al menu' principale
    }
//    else {
    sf::Vector2f offset(-sprite.getPosition().x, -sprite.getPosition().y);
    sprite.setPosition(map.getSpawnPoint());
    offset += sprite.getPosition();
    HP = maxHP;
    playerView.move(offset);
    if (playerView.getCenter().x - playerView.getSize().x / 4 < map.getViewHorizontalLimitSx())
        playerView.setCenter(playerView.getSize().x / 2, playerView.getCenter().y);
    if (playerView.getCenter().x - playerView.getSize().x / 4 > map.getViewHorizontalLimitDx())
        playerView.setCenter(map.getWidth() - playerView.getSize().x / 2, playerView.getCenter().y);
    if (playerView.getCenter().y + 40.f > map.getViewVerticalLimitDown())
        playerView.setCenter(playerView.getCenter().x, map.getHeight() - playerView.getSize().y / 2);
    if (playerView.getCenter().y + 40.f < map.getViewVerticalLimitUp())
        playerView.setCenter(playerView.getCenter().x, playerView.getSize().y / 2);
    gui->getText().clear();
    gui->getShapes().clear();
    gui->load(playerView);
    gui->updateLivesCount(lives);
    velocity.x = 0;
    velocity.y = 0;
//    }

}

void GameHero::loadGui() {
    gui->load(playerView);
}

std::vector<sf::Text *> &GameHero::getGuiText() {
    return gui->getText();
}

std::vector<sf::RectangleShape *> &GameHero::getGuiShapes() {
    return gui->getShapes();
}

Gui *GameHero::getGui() {
    return gui;
}

void GameHero::setHP(int hp, Map &map) {
    //Se il player possiede un bonus
    if (defenceBonus != nullptr) {
        //Se sta subendo danno
        if (HP > hp)
            //Si calcola il danno che sta venendo inflitto (HP - hp), se ne calcola la percentuale e si riaggiunge
            //al totale di hp da impostare
            HP = hp + ((HP - hp) * defenceBonus->getBonusValue()) / 100;
    } else {
        HP = hp;
    }
    if (HP <= 0)
        die(map);
    else if (HP > 100)
        HP = 100;
    gui->updateHealth(HP);
}

const sf::Clock &GameHero::getClock() const {
    return clock;
}

void GameHero::manageBonuses() {

    if (weapon->getAttackBonus() != nullptr) {
        if (clock.getElapsedTime().asSeconds() - weapon->getAttackBonus()->getCollectionTime() >
            weapon->getAttackBonus()->getDuration()) {
            delete weapon->getAttackBonus();
            weapon->setAttackBonus(nullptr);
        }
    }
    if (defenceBonus != nullptr) {
        if (clock.getElapsedTime().asSeconds() - defenceBonus->getCollectionTime() > defenceBonus->getDuration()) {
            delete defenceBonus;
            defenceBonus = nullptr;
        }
    }
}

void GameHero::setDefenceBonus(Bonus *dB) {
    GameHero::defenceBonus = dB;
}

void GameHero::checkEnemyCollision(Map &map) {

    const float tileSize = 21.f;

    for (Enemy *enemy : map.getEnemies()) {
        if (sprite.getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
            sprite.setPosition(sprite.getPosition().x, enemy->getSprite().getPosition().y - 21.f);
            velocity.y = 3 * jumpSpeed / 4;
            setHP(HP - enemy->getMeleeDamage(), map);
        }
    }

}

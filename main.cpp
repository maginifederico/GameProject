#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main() {

    //init game

    const float WINDOW_WIDTH  = 1920;
    const float WINDOW_HEIGHT  = 1040;
    float gridSizeWidthF = 21.f;
    float gridSizeHeightF = 19.f;
    //unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
    float dt = 0.f;
    Clock dtClock;

    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");

    //init view
    sf::View view;
    view.setSize(1920.f, 1080.f);
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    //init game elements
    //Player
    Texture pataTex;
    Sprite player;
    const float movementSpeed = 200.f;
    Vector2f velocity;

    if (!pataTex.loadFromFile("/home/federico/Documenti/ClionWorkspace/PatamanAdventure/Textures/singleBird_21x19.png"))
        std::cout << "Unable to load the sprite";

    player.setTexture(pataTex);
    //player.setScale(Vector2f(2.1f,1.9f));



    while (window.isOpen()) {


        //update dt
        dt = dtClock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //update input
        velocity.y = 0.f;
        velocity.x = 0.f;


        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            velocity.y += -movementSpeed * dt;
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            velocity.y += movementSpeed * dt;

        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            velocity.x += -movementSpeed * dt;

        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            velocity.x += movementSpeed * dt;

        }

        player.move(velocity);

        //collision screen
        //left collision
        if (player.getPosition().x < 0.f)
            player.setPosition(0.f, player.getPosition().y);

        //top collision
        if (player.getPosition().y < 0.f)
            player.setPosition(player.getPosition().x, 0.f);

        //right collision
        if (player.getPosition().x + player.getGlobalBounds().width > WINDOW_WIDTH)
            player.setPosition(WINDOW_WIDTH - player.getGlobalBounds().width, player.getPosition().y);

        //bottom collision
        if (player.getPosition().y + player.getGlobalBounds().height > WINDOW_HEIGHT)
            player.setPosition(player.getPosition().x, WINDOW_HEIGHT - player.getGlobalBounds().height);


        //render
        window.clear();
        window.setView(view);

        //render game elements
        window.draw(player);
        window.setView(window.getDefaultView());



        //render ui

        window.display();
    }

    return 0;


}
//    int main() {
//
//        //init game
//        float gridSizeWidthF = 21.f;
//        float gridSizeHeightF = 19.f;
//        //unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
//        float dt = 0.f;
//        Clock dtClock;
//
//        //init window
//        RenderWindow window(sf::VideoMode(1920, 1080), "PATAMAN ADVENTURES");
//
//        //init view
//        sf::View view;
//        view.setSize(1920.f, 1080.f);
//        view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
//        float viewSpeed = 200.f;
//
//        //init game elements
//        //RectangleShape rectangle(sf::Vector2f(gridSizeWidthF, gridSizeHeightF));
//        Texture pataTex;
//        Sprite player;
//
//        if(!pataTex.loadFromFile("/home/federico/Documenti/ClionWorkspace/PatamanAdventure/Textures/singleBird_21x19.png"))
//            std::cout << "Unable to load the sprite";
//
//        player.setTexture(pataTex);
//        //player.setScale(Vector2f(2.1f,1.9f));
//        std::vector<Sprite> potatoes;
//
//        //rectangle.setFillColor(sf::Color::Red);
//        //rectangle.setPosition(0, 0);
//
//
//        //CircleShape shape(100.f);
//        //shape.setFillColor(Color::Green);
//
//
//        while (window.isOpen()) {
//
//
//            //update dt
//            dt = dtClock.restart().asSeconds();
//
//            Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == Event::Closed) {
//                    window.close();
//                }
//            }
//
//            /*//update input
//            if (Keyboard::isKeyPressed(Keyboard::A)) { //LEFT
//                view.move(viewSpeed * dt, 0.f);
//            }
//    //update input
//            if (Keyboard::isKeyPressed(Keyboard::A)) { //LEFT
//                view.move(viewSpeed * dt, 0.f);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::D)) { //RIGHT
//                view.move(-viewSpeed * dt, 0.f);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::W)) { //UP
//                view.move(0.f, viewSpeed * dt);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::S)) { //DOWN
//                view.move(0.f, -viewSpeed * dt);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::D)) { //RIGHT
//                view.move(-viewSpeed * dt, 0.f);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::W)) { //UP
//                view.move(0.f, viewSpeed * dt);
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::S)) { //DOWN
//                view.move(0.f, -viewSpeed * dt);
//            }
//    */
//
//            //collision screen
//            //left collision
//            if(player.getPosition().x < 0.f)
//                player.setPosition(0.f, player.getPosition().y);
//
//
//            //render
//            window.clear();
//            window.setView(view);
//
//            //render game elements
//            //window.draw(rectangle);
//            window.draw(player);
//            window.setView(window.getDefaultView());
//
//
//
//            //render ui
//
//            //window.draw(shape);
//            //window.draw(rectangle);
//            window.display();
//        }
//
//        return 0;
//}
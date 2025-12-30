#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

sf::Vector2f normalize(sf::Vector2f dir) {
  float m = std::sqrt(dir.x* dir.x+dir.y*dir.y);

  sf::Vector2f normalizedVector;

  normalizedVector.x = dir.x / m;
  normalizedVector.y = dir.y / m;

  return normalizedVector;

};

int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 900, 680 }), "My window", sf::Style::Default, sf::State::Windowed, settings);

    sf::RectangleShape bullet(sf::Vector2f(50,25));
    bullet.setPosition(sf::Vector2f(0, 600));
    float speed = 0.5f;

    //-------------------------------INITIALIZE-------------------------------

    //-------------------------------LOAD-------------------------------

    //-------------------------------Skeleton-------------------------------

    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite(skeletonTexture); //we need to give empty texture to the sprite

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        skeletonSprite.setTexture(skeletonTexture, true);
      skeletonSprite.setPosition(sf::Vector2f(600, 400));
        int xIndex = 5;
        int yIndex = 2;

        skeletonSprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        skeletonSprite.setScale(sf::Vector2f(3, 3));
        std::cout << "enemy sprite Loaded" << std::endl;
    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    };
    //-------------------------------Skeleton-------------------------------

    //-------------------------------player-------------------------------

    sf::Texture playerTexture;
    sf::Sprite playerSprite(playerTexture); //we need to give empty texture to the sprite

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        playerSprite.setTexture(playerTexture, true);

        int xIndex = 5;
        int yIndex = 1;

        playerSprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        playerSprite.setScale(sf::Vector2f(3, 3));
        std::cout << "player sprite Loaded" << std::endl;

    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    }
    //-------------------------------player-------------------------------


//-------------------------------LOAD-------------------------------

//-------------------------------Calculate the bullet tragectry-------------------------------
    sf::Vector2f direction = skeletonSprite.getPosition() - bullet.getPosition();
    direction = normalize(direction);

//-------------------------------Calculate the bullet tragectry-------------------------------
    while (window.isOpen()) {
        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) 
                window.close();
        }

        bullet.setPosition(bullet.getPosition() + direction * speed);

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        window.draw(playerSprite);
        window.draw(skeletonSprite);
        window.draw(bullet);

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

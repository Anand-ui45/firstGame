#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    std::vector<std::string> favgames;
    favgames.reserve(8);


    favgames.push_back("resident Evil 5");
    favgames.push_back("resident Evil 4");
    favgames.push_back("Batman Ark ashylm");
    favgames.push_back("Batman Ark city");
    favgames.push_back("Doom");
    favgames.push_back("Toomb raider");
    favgames.push_back("AC3");
    favgames.push_back("AC4");
   
    std::cout << favgames.capacity() << std::endl;

    for (size_t i = 0; i < favgames.size(); i++)
    {
        std::cout << favgames[i]<<" "<< &favgames[i] << std::endl;
        std::cout << i<< std::endl;
    }














    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 900, 680 }), "My window", sf::Style::Default, sf::State::Windowed, settings);


    //-------------------------------INITIALIZE-------------------------------

    //-------------------------------LOAD-------------------------------

    //-------------------------------Skeleton-------------------------------

    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite(skeletonTexture); //we need to give empty texture to the sprite

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        skeletonSprite.setTexture(skeletonTexture, true);
      skeletonSprite.setPosition(sf::Vector2f(400, 100));
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



    while (window.isOpen()) {
        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>())
                window.close();
        }
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

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

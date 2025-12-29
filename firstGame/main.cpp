#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    
   //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
   
    //-------------------------------For Testing Porpouse-------------------------------
   sf::ContextSettings const set = window.getSettings();
   std::cout << set.antiAliasingLevel << std::endl;
   //-------------------------------For Testing Porpouse-------------------------------

   

   //-------------------------------INITIALIZE-------------------------------

   //-------------------------------LOAD-------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite(playerTexture); //we need to give empty texture to the sprite

        if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
            playerSprite.setTexture(playerTexture,true);

            int xIndex = 5;
            int yIndex = 2;

            playerSprite.setTextureRect(sf::IntRect({ xIndex*64, yIndex*64 }, { 64, 64 }));
            playerSprite.setScale(sf::Vector2f(3, 3));
            std::cout << "sprite Loaded" << std::endl;

        }
        else {
            std::cout << "sprite not Loaded" << std::endl;

        }
   //-------------------------------LOAD-------------------------------



    while (window.isOpen()){
   //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()){
          
           
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
       
        window.display();
   //-------------------------------DRAW-------------------------------

    }
}

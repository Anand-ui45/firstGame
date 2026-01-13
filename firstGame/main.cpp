#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include <iostream>


int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
   

   

    FrameRate frameRate;
    Player player;
    Skeleton skeleton;

    skeleton.Initialize();
    player.Initialize();
    frameRate.Initialize();

    //-------------------------------INITIALIZE-------------------------------

    

  
    //-------------------------------LOAD-------------------------------
  
    frameRate.Load();
    player.Load();
    skeleton.Load();

   
    //-------------------------------LOAD-------------------------------
    sf::Clock clock;

    while (window.isOpen()) {


        sf::Time deltatimeTimer = clock.restart();
        double deltatime = deltatimeTimer.asMicroseconds()/1000.0;

       
        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) 
                window.close();
        }

       
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        frameRate.Update(deltatime);
        player.Update(deltatime,skeleton,mousePosition);
        skeleton.Update(deltatime);

        
        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);
        
        frameRate.Draw(window);
        player.Draw(window);
        skeleton.Draw(window);
        

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

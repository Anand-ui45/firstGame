#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"
#include <iostream>


int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);

    Player player;
    Skeleton skeleton;

    skeleton.Initialize();
    player.Initialize();
   
    //-------------------------------INITIALIZE-------------------------------

    

  
    //-------------------------------LOAD-------------------------------


    player.Load();
    skeleton.Load();

   
    //-------------------------------LOAD-------------------------------
    sf::Clock clock;

    while (window.isOpen()) {


        sf::Time deltatimeTimer = clock.restart();
        float deltatime = deltatimeTimer.asMilliseconds();

        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) 
                window.close();
        }

       

        player.Update(deltatime,skeleton);
        skeleton.Update(deltatime);

        
        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        player.Draw(window);
        skeleton.Draw(window);
        

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

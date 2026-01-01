#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"



int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 900, 680 }), "My window", sf::Style::Default, sf::State::Windowed, settings);

    Player player;
    Skeleton skeleton;

    skeleton.Initialize();
    player.Initialize();
   
    //-------------------------------INITIALIZE-------------------------------

    

  
    //-------------------------------LOAD-------------------------------


    player.Load();
    skeleton.Load();

   
    //-------------------------------LOAD-------------------------------

    while (window.isOpen()) {
        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) 
                window.close();
        }


        player.Update(skeleton);
        skeleton.Update();

        
        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        player.Draw(window);
        skeleton.Draw(window);
        

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

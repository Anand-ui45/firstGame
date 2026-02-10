#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"





int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "My Editor window", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(140);

    Grid grid(sf::Vector2f(0,0), sf::Vector2i(16, 16),sf::Vector2i(10,5), sf::Vector2i(10,10),sf::Color(255,255,255,100), 2);
    MouseTile mouseTile(sf::Vector2i(16,16), sf::Vector2f(10,10), sf::Vector2f(0, 0));
    Map map(mouseTile);

    grid.Initialize();
    mouseTile.Initialize();
    map.Intailize();
    //-------------------------------INITIALIZE-------------------------------



    //-------------------------------LOAD-------------------------------
    grid.Load();
    mouseTile.Load();
    map.Load();


    //-------------------------------LOAD-------------------------------
    sf::Clock clock;

    while (window.isOpen()) {


        sf::Time deltatimeTimer = clock.restart();
        double deltatime = deltatimeTimer.asMicroseconds() / 1000.0;


        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>())
                window.close();
        }


        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
      
        grid.Update(deltatime);
        mouseTile.Update(deltatime,mousePosition);
        map.Update(deltatime);


        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        map.Draw(window);
        grid.Draw(window);
        mouseTile.Draw(window);
        
        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

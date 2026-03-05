#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "gui/Button.h"
#include "MapSaver.h"
#include <core/MapData.h>





int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1080,800 }), "My Editor window", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(140);

    Grid grid(sf::Vector2f(0,150), sf::Vector2i(16, 16),sf::Vector2i(10,5), sf::Vector2i(5,5),sf::Color(255,255,255,100), 2);
    MouseTile mouseTile(grid, sf::Vector2i(16,16), sf::Vector2f(5,5), sf::Vector2f(0, 150));
    Map map(grid,mouseTile);
    gui::Button button(sf::Vector2f(50, 50), sf::Vector2f(3, 3));
    MapSaver mSaver;

   

    grid.Initialize();
    mouseTile.Initialize();
    map.Initialize();
    button.Initialize();
    //-------------------------------INITIALIZE-------------------------------



    //-------------------------------LOAD-------------------------------
    grid.Load();
    mouseTile.Load();
    map.Load();
    button.Load();



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
        button.Update(deltatime,mousePosition);

        if (button.IsPressed()) {
            MapData mapData(
                "assets/world/prison/tilesheet.png",
                "Level 1",
                grid.GetPosition().x,
                grid.GetPosition().y,
                grid.GetCellSize().x,
                grid.GetCellSize().x,
                grid.GetTotalCells().x,
                grid.GetTotalCells().y,
                grid.GetScale().x,
                grid.GetScale().y,
                grid.GetTotalCells().x * grid.GetTotalCells().y,
                map.GetTileIDs()
            );


            mSaver.Save("test1.rmap", mapData);
            std::cout << "map is saved" << std::endl;
        }


        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        map.Draw(window);
        grid.Draw(window);
        mouseTile.Draw(window);
        button.Draw(window);
        
        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

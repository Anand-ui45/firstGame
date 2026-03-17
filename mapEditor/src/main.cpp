#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "gui/Button.h"
#include "MapSaver.h"
#include <core/MapData.h>
#include "TileSelectionPane.h"

int main() {
    //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "My Editor window", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(140);

    Grid grid(sf::Vector2f(0, 150), sf::Vector2i(16, 16), sf::Vector2i(20, 10), sf::Vector2i(3, 3), sf::Color(255, 255, 255, 100), 2);
    MouseTile mouseTile(grid, sf::Vector2i(16, 16), sf::Vector2f(3, 3), sf::Vector2f(0, 150));
    Map map(grid, mouseTile);
    gui::Button button(sf::Vector2f(50, 50), sf::Vector2f(3, 3));
    MapSaver mSaver(grid);
    TileSelectionPane tileSP;

    grid.Initialize();
    mouseTile.Initialize();
    map.Initialize();
    button.Initialize();
    tileSP.Initialize();
    //------------------------------------------------------------------------

    //-------------------------------LOAD-------------------------------
    grid.Load();
    mouseTile.Load();
    map.Load();
    button.Load();
    tileSP.Load();

    int tileIndex = 0;
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
        mouseTile.Update(deltatime, mousePosition);
        map.Update(deltatime);
        button.Update(deltatime, mousePosition);
        tileSP.Update(mousePosition);

        // Update tile selection
        tileIndex = tileSP.IsPressed();
        if (tileIndex != -1) {
            mouseTile.SetCurrentTileID(tileIndex);
        }

        // --- NEW: LAYER SWITCHING (Moved outside of the button check) ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num1)) map.SetActiveLayer(0); // Ground
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num2)) map.SetActiveLayer(1); // Objects
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num3)) map.SetActiveLayer(2); // Foreground

        // Save logic
        if (button.IsPressed()) {
            // Create MapData with the new layer-aware constructor
            MapData mapData(
                "assets/world/prison/tilesheet.png",
                "Level 1",
                grid.GetPosition().x,
                grid.GetPosition().y,
                grid.GetCellSize().x,
                grid.GetCellSize().y,
                grid.GetTotalCells().x,
                grid.GetTotalCells().y,
                grid.GetScale().x,
                grid.GetScale().y,
                map.GetNumLayers(),                     // Added: Number of layers
                grid.GetTotalCells().x * grid.GetTotalCells().y, // Data length per layer
                &map.GetAllLayerIDs()                   // Added: Pointer to the full 2D vector
            );

            mSaver.Save("test1.rmap", mapData, map);
            std::cout << "Map saved with " << map.GetNumLayers() << " layers!" << std::endl;
        }
        //--------------------------------------------------------------------

        //-------------------------------DRAW-------------------------------
        window.clear(sf::Color::Black);

        map.Draw(window);
        grid.Draw(window);
        tileSP.Draw(window);
        mouseTile.Draw(window);
        button.Draw(window);

        window.display();
        //------------------------------------------------------------------
    }

    return 0;
};
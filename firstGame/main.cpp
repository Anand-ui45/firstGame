#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    
   //-------------------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
   

   sf::ContextSettings const set = window.getSettings();
   std::cout << set.antiAliasingLevel << std::endl;
    sf::CircleShape shape(50.5f);
    sf::RectangleShape shape2(sf::Vector2f(100.6f, 50.4f));
    sf::CircleShape poly(120.f,8);
   
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(400.5f,300.6f));
    shape.setOutlineThickness(12.7f);
    shape.setOutlineColor(sf::Color::Red);

    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(sf::Vector2f(400.5f, 300.6f));
    shape2.setOutlineThickness(12.7f);
    shape2.setOutlineColor(sf::Color::Red);
    shape2.setOrigin(shape2.getSize()/2.f);
    shape2.setRotation(sf::degrees(45));

    poly.setFillColor(sf::Color::Blue);
    poly.setPosition(sf::Vector2f(100.5f, 300.6f));
    poly.setOutlineThickness(12.7f);
    poly.setOutlineColor(sf::Color::Red);
    
    

   //-------------------------------INITIALIZE-------------------------------

    while (window.isOpen()){
   //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()){
          
           
            if (event->is<sf::Event::Closed>())
                window.close();
        }
   //-------------------------------UPDATE-------------------------------

   //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(shape2);
        window.draw(poly);
       
        window.display();
   //-------------------------------DRAW-------------------------------

    }
}

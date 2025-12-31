#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Skeleton.h"

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

    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f direction;
    float speed = 0.5f;

    Player player;

    player.Initialize();
    player.Load();

    //-------------------------------INITIALIZE-------------------------------

    //-------------------------------LOAD-------------------------------

    //-------------------------------Skeleton-------------------------------

    Skeleton skeleton;

    skeleton.Initialize();
    skeleton.Load();
    //-------------------------------Skeleton-------------------------------

    //-------------------------------player-------------------------------

   
    //-------------------------------player-------------------------------


//-------------------------------LOAD-------------------------------

//-------------------------------Calculate the bullet tragectry-------------------------------
    

//-------------------------------Calculate the bullet tragectry-------------------------------
    while (window.isOpen()) {
        //-------------------------------UPDATE-------------------------------
        while (const std::optional event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) 
                window.close();
        }


        player.Update();
        skeleton.Update();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
            int lastI = bullets.size() - 1;
            bullets[lastI].setPosition(player.sprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            
            sf::Vector2f direction = skeleton.sprite.getPosition() - bullets[i].getPosition();
            direction = normalize(direction);
            bullets[i].setPosition(bullets[i].getPosition() + direction * speed);

        }
        //-------------------------------UPDATE-------------------------------

        //-------------------------------DRAW-------------------------------

        window.clear(sf::Color::Black);

        window.draw(player.sprite);
        window.draw(skeleton.sprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {

        window.draw(bullets[i]);
        }

        window.display();
        //-------------------------------DRAW-------------------------------

    }
};

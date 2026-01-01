#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize(){

    boundingRectangel.setFillColor(sf::Color::Transparent);
    boundingRectangel.setOutlineColor(sf::Color::Red);
    boundingRectangel.setOutlineThickness(1);
    size = sf::Vector2i(64,64);
    
}

void Player::Load(){
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        sprite.setTexture(texture, true);

        int xIndex = 5;
        int yIndex = 1;

        sprite.setTextureRect(sf::IntRect({ xIndex * size.x, yIndex * size.y }, { size.x, size.y }));
        sprite.setPosition(sf::Vector2f(0, 0));

        sprite.setScale(sf::Vector2f(3, 3));
        boundingRectangel.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
        
        std::cout << "player sprite Loaded" << std::endl;

    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
        int lastI = bullets.size() - 1;
        bullets[lastI].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        sf::Vector2f direction = skeleton.sprite.getPosition() - bullets[i].getPosition();
        direction = Math::Normalize(direction);
        bullets[i].setPosition(bullets[i].getPosition() + direction * speed);

    }
    boundingRectangel.setPosition(sprite.getPosition());

    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
        std::cout << "collision" << std::endl;
    }
}



void Player::Draw(sf::RenderWindow& window){

    window.draw(sprite);
    window.draw(boundingRectangel);
    for (size_t i = 0; i < bullets.size(); i++)
    {

        window.draw(bullets[i]);
    }

}



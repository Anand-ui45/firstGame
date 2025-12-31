#include "Player.h"
#include <iostream>

void Player::Initialize(){


}

void Player::Load(){
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        sprite.setTexture(texture, true);

        int xIndex = 5;
        int yIndex = 1;

        sprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        sprite.setScale(sf::Vector2f(3, 3));
        std::cout << "player sprite Loaded" << std::endl;

    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    }
}

void Player::Update()
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
}

void Player::Draw()
{
}

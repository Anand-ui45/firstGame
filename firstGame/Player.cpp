#include "Player.h"
#include <iostream>
#include "Math.h"

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
}



void Player::Draw(sf::RenderWindow& window){

    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++)
    {

        window.draw(bullets[i]);
    }

}



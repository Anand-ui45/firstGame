#include "Skeleton.h"
#include <iostream>



void Skeleton::ChangeHealth(int hp)
{
     health += hp;
     text.setString(std::to_string(health));
    
}

Skeleton::Skeleton():sprite(texture), health(100),text(font){
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize(){
     
    boundingRectangel.setFillColor(sf::Color::Transparent);
    boundingRectangel.setOutlineColor(sf::Color::Red);
    boundingRectangel.setOutlineThickness(1);
    size = sf::Vector2i(64, 64);
}

void Skeleton::Load(){
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        sprite.setTexture(texture, true);
        sprite.setPosition(sf::Vector2f(600, 400));
        int xIndex = 5;
        int yIndex = 2;

        sprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        
        sprite.setScale(sf::Vector2f(3, 3));
        boundingRectangel.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

        std::cout << "enemy sprite Loaded" << std::endl;
    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    };
    if (font.openFromFile("Assets/Fonts/arial.ttf")) {
        text.setFont(font);
    };

    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setString(std::to_string(health));

}

void Skeleton::Update(float deltatime){
    if (health > 0) {
        boundingRectangel.setPosition(sprite.getPosition());
        text.setPosition(boundingRectangel.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow& window){
    if (health > 0) {
        window.draw(text);
        window.draw(boundingRectangel);
        window.draw(sprite);
    }
}



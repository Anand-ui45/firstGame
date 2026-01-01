#include "Skeleton.h"
#include <iostream>

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
}

void Skeleton::Update(){
    boundingRectangel.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window){
    window.draw(boundingRectangel);
    window.draw(sprite);

}



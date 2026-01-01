#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize(){

}

void Skeleton::Load(){
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        sprite.setTexture(texture, true);
        sprite.setPosition(sf::Vector2f(600, 400));
        int xIndex = 5;
        int yIndex = 2;

        sprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        sprite.setScale(sf::Vector2f(3, 3));
        std::cout << "enemy sprite Loaded" << std::endl;
    }
    else {
        std::cout << "sprite not Loaded" << std::endl;

    };
}

void Skeleton::Update(){

}

void Skeleton::Draw(sf::RenderWindow& window){

    window.draw(sprite);

}



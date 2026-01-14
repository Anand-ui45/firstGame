#include "Math.h"
#include "Player.h"
#include <iostream>

Player::Player(): sprite(texture),playerSpeed(1.f),maxFireRate(150),fireRateTimer(0){
    
}

Player::~Player()
{
}

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

void Player::Update(float deltatime,Skeleton& skeleton, sf::Vector2f &mousePosition)
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.setPosition(position + sf::Vector2f(0, -1)*playerSpeed*deltatime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0)*playerSpeed * deltatime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltatime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltatime);


//-------------------------------------------------------------------------------------------------
    fireRateTimer += deltatime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&&fireRateTimer>=maxFireRate) {
        bullets.push_back(Bullet());
        int lastI = bullets.size() - 1;
        bullets[lastI].Initialize(sprite.getPosition(),mousePosition, .5f);
       
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
       

        bullets[i].Update(deltatime);
        
    


        if (skeleton.health>0) {
            if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
                skeleton.ChangeHealth(-10);
                bullets.erase(bullets.begin() + i);
            }
           

        }

    }
    boundingRectangel.setPosition(sprite.getPosition());

    
//-----------------------------------------------------------------------------------------------------------------
}



void Player::Draw(sf::RenderWindow& window){

    window.draw(sprite);
    window.draw(boundingRectangel);
    for (size_t i = 0; i < bullets.size(); i++)
    {

        bullets[i].Draw(window);
    }

}



#include "Bullet.h"
#include "Math.h"


Bullet::Bullet():speed(0){
}

Bullet::~Bullet(){
}

void Bullet::Initialize(const sf::Vector2f& position,const sf::Vector2f& target ,float speed){
	this->speed = speed;
	rectangleShape.setSize(sf::Vector2f(50,25));
	rectangleShape.setPosition(position);
	direction = Math::Normalize(target - position);
	
}


void Bullet::Load()
{
}

void Bullet::Update(float deltatime){
	rectangleShape.setPosition(rectangleShape.getPosition()+direction *speed*deltatime);
}

void Bullet::Draw(sf::RenderWindow& window){
	window.draw(rectangleShape);
}

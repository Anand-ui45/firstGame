#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.f;
	float playerSpeed = 2.0f;

	sf::RectangleShape boundingRectangel;

	sf::Vector2i size;
	
public:
	sf::Sprite sprite;
	Player() :sprite(texture) {};
	void Initialize();
	void Load();
	void Update(float deltatime,Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};


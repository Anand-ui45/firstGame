#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed;
	float playerSpeed;

	sf::RectangleShape boundingRectangel;

	sf::Vector2i size;
	
public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(float deltatime,Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};


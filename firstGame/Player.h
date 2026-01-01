#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float speed = 1.f;
	
public:
	sf::Sprite sprite;
	Player() :sprite(texture) {};
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};


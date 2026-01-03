#pragma once
#include <SFML/Graphics.hpp>

class Skeleton{
private:
	sf::Texture texture;
	sf::RectangleShape boundingRectangel;

	sf::Vector2i size;
public:
	sf::Sprite sprite;
	Skeleton() :sprite(texture) {};
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


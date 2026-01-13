#pragma once
#include <SFML/Graphics.hpp>

class Skeleton{
private:
	sf::Texture texture;
	sf::RectangleShape boundingRectangel;
	sf::Vector2i size;
	sf::Font font;
	sf::Text text;
public:
	sf::Sprite sprite;
	void ChangeHealth(int hp);
	int health;
	Skeleton();
	~Skeleton();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


#pragma once
#include <SFML/Graphics.hpp>

class Skeleton{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;
	Skeleton() :sprite(texture) {};
	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
};


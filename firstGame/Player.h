#pragma once
#include <SFML/Graphics.hpp>

class Player{
private:
	sf::Texture texture;
	
public:
	sf::Sprite sprite;
	Player() :sprite(texture) {};
	void Initialize();
	void Load();
	void Update();
	void Draw();
};


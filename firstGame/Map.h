#pragma once
#include <SFML/Graphics.hpp>

class Map{
private:
	sf::Texture tileTexture;
	const static int tileSpriteSize = 10;
	std::vector<sf::Sprite> tileSprites;
	
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;


public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


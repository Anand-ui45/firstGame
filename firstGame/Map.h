#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map{
private:
	sf::Texture tileTexture;
	int totalTiles;
	Tile* tiles;
	
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;
	int mapNumbers[6] = {120,121,122,144,145,146};
	std::vector<sf::Sprite> mapSprties;


public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


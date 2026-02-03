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
	static const int mapArraySize = 6;
	int mapWidth;
	int mapHeight;
	int mapNumbers[mapArraySize] = {120,121,122,144,145,146};
	std::vector<sf::Sprite> mapSprties;


public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


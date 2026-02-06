#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map{
private:
	sf::Texture tileTexture;
	int totalTiles;
	Tile* tiles;

	MapLoader maploader;
	MapData mapsData;
	
	
	int totalTilesX;
	int totalTilesY;
	
	
	
	std::vector<sf::Sprite> mapSprties;


public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};


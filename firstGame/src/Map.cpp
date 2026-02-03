#include "Map.h"
#include <iostream>

Map::Map():tileWidth(16),tileHeight(16),totalTilesX(0),totalTilesY(0),totalTiles(0),mapHeight(2),mapWidth(3),tiles(nullptr){
	
	for (size_t i = 0; i < mapArraySize; i++) {
		mapSprties.emplace_back(tileTexture);
	}
}

Map::~Map(){
	delete tiles;
}

void Map::Initialize(){

}

void Map::Load(){
	if (tileTexture.loadFromFile("assets/world/prison/tilesheet.png")) {
     
		std::cout << "map loaded" << std::endl;
		totalTilesX = tileTexture.getSize().x / 16;//24
		totalTilesY = tileTexture.getSize().y / 16;//12

		int xIndex = 0;
		int yIndex = 0;
		
		totalTiles = totalTilesX * totalTilesY;

		tiles = new Tile[totalTiles];
	

		for (int y = 0; y < totalTilesY; y++) {
			for (int x = 0; x < totalTilesX; x++) {

				int i = x + y * totalTilesX;
				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
				
		
			}
		}

	}
	else {
		std::cout << "map not loaded" << std::endl;
	}
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			int i = x + y * mapWidth;
			int index = mapNumbers[i];

			if (i < mapSprties.size()) {
				mapSprties[i].setTexture(tileTexture);
				mapSprties[i].setTextureRect(sf::IntRect({ tiles[index].position.x, tiles[index].position.y }, { tileHeight, tileWidth }));
				mapSprties[i].setScale({ 5, 5 });
				mapSprties[i].setPosition({ 100+ x * tileWidth * mapSprties[i].getScale().x, 100 + y * tileHeight * mapSprties[i].getScale().y});
			}
		}
	}
}

void Map::Update(float deltatime)
{
}

void Map::Draw(sf::RenderWindow& window){
	for (int i = 0; i < mapArraySize; i++) {
		window.draw(mapSprties[i]);
	}
	
}

#include "Map.h"
#include <iostream>

Map::Map():tileWidth(16),tileHeight(16),totalTilesX(0),totalTilesY(0),totalTiles(0){
	
	for (size_t i = 0; i < 6; i++) {
		mapSprties.emplace_back(tileTexture);
	}
}

Map::~Map(){
}

void Map::Initialize(){

}

void Map::Load(){
	if (tileTexture.loadFromFile("Assets/World/Prison/tilesheet.png")) {
     
		std::cout << "map loaded" << std::endl;
		totalTilesX = tileTexture.getSize().x / 16;//24
		totalTilesY = tileTexture.getSize().y / 16;//12

		int xIndex = 0;
		int yIndex = 0;
		
		totalTiles = totalTilesX * totalTilesY;

		tiles = new Tile[totalTiles];
	

		for (int x = 0; x < totalTilesX; x++) {
			for (int y = 0; y < totalTilesY; y++) {

				int i = x + y * totalTilesX;
				tiles[i].id = i;
			
				int pointX = x * tileWidth;
				int pointY = y * tileHeight;


				tiles[i].position = sf::Vector2i(pointX,pointY);
				//float scale = 4.50f; // Reduced scale from 5 to 3 so they fit better
				//float screenX = pointX  * scale;
				//float screenY = pointY  * scale;

				//currentTile.sprite.setPosition({ screenX, screenY });
				//currentTile.sprite.setScale({ scale, scale });
		
			}
		}

	}
	else {
		std::cout << "map not loaded" << std::endl;
	}
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 3; y++) {
			int i = x + y * 3;
			int index = mapNumbers[i];
			float scale = 4.50f; // Reduced scale from 5 to 3 so they fit better
			float screenX = x * 16 * scale;
			float screenY = y * 16 * scale;

			if (i < mapSprties.size()) {
				mapSprties[i].setTexture(tileTexture);

				
				mapSprties[i].setTextureRect(sf::IntRect({ tiles[index].position.x, tiles[index].position.y }, { tileHeight, tileWidth }));
				mapSprties[i].setScale({ scale, scale });
				mapSprties[i].setPosition({ 100+screenX, 100+screenY });
			}
		}
	}
}

void Map::Update(float deltatime)
{
}

void Map::Draw(sf::RenderWindow& window){
	for (size_t i = 0; i < 6; i++) {
		window.draw(mapSprties[i]);
	}
	
}

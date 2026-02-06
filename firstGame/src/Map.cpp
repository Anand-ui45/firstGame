#include "Map.h"
#include <iostream>

Map::Map():totalTilesX(0),totalTilesY(0),totalTiles(0),tiles(nullptr){
	
	maploader.Load("assets/maps/level_1.rmap", mapsData);//its load data from file and saved the data to the second arugement
	mapSprties.reserve(mapsData.dataLength);
	for (size_t i = 0; i < mapsData.dataLength; i++) {
		mapSprties.emplace_back(tileTexture);
	}
}

Map::~Map(){
	delete tiles;
}

void Map::Initialize(){

}

void Map::Load(){




	if (tileTexture.loadFromFile(mapsData.tilesheet)) {
     
		std::cout << "map loaded" << std::endl;
		totalTilesX = tileTexture.getSize().x / mapsData.cellSizeX;//24
		totalTilesY = tileTexture.getSize().y / mapsData.cellSizeY;//12

		int xIndex = 0;
		int yIndex = 0;
		
		totalTiles = totalTilesX * totalTilesY;

		tiles = new Tile[totalTiles];
	

		for (int y = 0; y < totalTilesY; y++) {
			for (int x = 0; x < totalTilesX; x++) {

				int i = x + y * totalTilesX;
				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * mapsData.cellSizeX, y * mapsData.cellSizeY);
				
		
			}
		}

	}
	else {
		std::cout << "map not loaded" << std::endl;
	}
	for (int y = 0; y < mapsData.totalCellsY; y++) {
		for (int x = 0; x < mapsData.totalCellsX; x++) {
			int i = x + y * mapsData.totalCellsX;
			int index = mapsData.data[i];

			if (i < mapSprties.size()) {
				mapSprties[i].setTexture(tileTexture);
				mapSprties[i].setTextureRect(sf::IntRect({ tiles[index].position.x, tiles[index].position.y }, { mapsData.cellSizeX, mapsData.cellSizeY }));
				mapSprties[i].setScale(sf::Vector2f( mapsData.mapScaleX, mapsData.mapScaleY ));
				mapSprties[i].setPosition(sf::Vector2f( mapsData.mapPositionX+ x * mapsData.cellSizeX * mapsData.mapScaleX, mapsData.mapPositionY + y * mapsData.cellSizeY * mapsData.mapScaleY ));
			}
		}
	}
}

void Map::Update(float deltatime)
{
}

void Map::Draw(sf::RenderWindow& window){
	for (int i = 0; i < mapsData.dataLength; i++) {
		window.draw(mapSprties[i]);
	}
	
}

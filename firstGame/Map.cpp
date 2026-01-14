#include "Map.h"
#include <iostream>
Map::Map():tileWidth(16),tileHeight(16),totalTilesX(0),totalTilesY(0){
	
	tileSprites.reserve(tileSpriteSize);
	// Now we construct them one-by-one into that reserved memory.
	for (int i = 0; i < tileSpriteSize; i++) {
		tileSprites.emplace_back(tileTexture);
	}
}

Map::~Map(){
}

void Map::Initialize(){

}

void Map::Load(){
	if (tileTexture.loadFromFile("Assets/World/Prison/tilesheet.png")) {
		std::cout << "map loaded" << std::endl;
		totalTilesX = tileTexture.getSize().x / 16;
		totalTilesY = tileTexture.getSize().y / 16;

		int xIndex = 0;
		int yIndex = 0;
	
		for (int i = 0; i < tileSpriteSize; i++) {


			tileSprites[i].setTexture(tileTexture, true);
			

			tileSprites[i].setTextureRect(sf::IntRect({i * tileWidth, 0}, {tileWidth, tileHeight}));
			tileSprites[i].setPosition(sf::Vector2f(i*tileWidth*5, 0));
			tileSprites[i].setScale(sf::Vector2f(5, 5));
		
			
		}

	}
	else {
		std::cout << "map not loaded" << std::endl;
	}
}

void Map::Update(float deltatime)
{
}

void Map::Draw(sf::RenderWindow& window){
	for (int i = 0; i < tileSpriteSize; i++) {
		window.draw(tileSprites[i]);
	}
	
}

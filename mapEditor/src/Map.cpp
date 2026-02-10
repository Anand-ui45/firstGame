#include "Map.h"
#include <iostream>

Map::Map(MouseTile& mouseTile):m_mouseTile(mouseTile) {
	for (int i = 0; i < MAP_SIZE; i++)
	{
		m_mapSprties.emplace_back(m_tileTexture);
	}
}

Map::~Map() {

}

void Map::Intailize() {

}

void Map::Load() {

}

void Map::Update(float deltatime) {
	sf::Vector2f tilePosition;
	if (m_mouseTile.isMouseClickedOnTile(tilePosition)) {
		std::cout << tilePosition.x << std::endl;
			std::cout << tilePosition.y << std::endl;
	}
}

void Map::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAP_SIZE; i++)
	{
		window.draw(m_mapSprties[i]);
	}
}

#include "Map.h"
#include <iostream>

Map::Map(const Grid& grid, const MouseTile& mouseTile): m_grid(grid), m_mouseTile(mouseTile) {
	for (int i = 0; i < MAP_SIZE; i++)
	{
		m_mapSprties.emplace_back(m_tileTexture);
		
	}
}

Map::~Map() {

}

void Map::Initialize() {
	m_tileIDs = new int[MAP_SIZE];
	memset(m_tileIDs, 0, sizeof(int) * MAP_SIZE);
}

void Map::Load() {

}

void Map::Update(float deltatime) {
	sf::Vector2f tilePosition;
	sf::Vector2i gridPosition;
	if (m_mouseTile.isMouseClickedOnTile(tilePosition,gridPosition)) {

	int i = gridPosition.x + gridPosition.y * m_grid.GetTotalCells().x;
	m_tileIDs[i] = m_mouseTile.GetCurrentTileID();
		m_mapSprties[i] = m_mouseTile.GetTileSprite();
	}
}

void Map::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAP_SIZE; i++)
	{
		window.draw(m_mapSprties[i]);
	}
}

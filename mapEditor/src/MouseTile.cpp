#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(const Grid& grid,
	const sf::Vector2i& tileSize,
	const sf::Vector2f& tileScale,
	const sf::Vector2f offset) :
	m_tile(m_tileSheet),
	m_grid(grid),
	m_tileSize(tileSize),
	m_tileScale(tileScale),
    m_offset(offset),
    m_isMouseOnGrid(false){

}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load(){
	if (m_tileSheet.loadFromFile("assets/world/prison/tilesheet.png")) {
	m_tile.setTexture(m_tileSheet,true);
	m_tilesPerRow = m_tileSheet.getSize().x / m_tileSize.x;

	m_currentTileID = 11;
	m_tile.setTextureRect({ {m_currentTileID * m_tileSize.x,0}, { m_tileSize.x,m_tileSize.y } });
	m_tile.setScale(sf::Vector2f(m_tileScale.x, m_tileScale.y));
	}
	else {
		std::cout << "not working" << std::endl;
	}


}

void MouseTile::Update(float deltatime, const sf::Vector2f& mousePosition) {
	const sf::Vector2f& gridPosition = m_grid.GetPosition();
	const sf::Vector2f& gridSize = m_grid.GetSize();
	const sf::Vector2i& totalCells = m_grid.GetTotalCells(); // Get grid limits

	int tx = (m_currentTileID % m_tilesPerRow) * m_tileSize.x;
	int ty = (m_currentTileID / m_tilesPerRow) * m_tileSize.y;
	
		m_tile.setTextureRect({ {tx, ty}, { m_tileSize.x,m_tileSize.y } });



	if ((mousePosition.x > gridPosition.x && mousePosition.x < gridPosition.x + gridSize.x) &&
		(mousePosition.y > gridPosition.y && mousePosition.y < gridPosition.y + gridSize.y)) {

		// Calculate raw index
		int rawX = (mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
		int rawY = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);

		// CLAMP: Ensure indices are never less than 0 or >= total cells
		m_tileIndex.x = std::max(0, std::min(rawX, totalCells.x - 1));
		m_tileIndex.y = std::max(0, std::min(rawY, totalCells.y - 1));

		m_snapPosition.x = m_tileIndex.x * (m_tileSize.x * m_tileScale.x) + m_offset.x;
		m_snapPosition.y = m_tileIndex.y * (m_tileSize.y * m_tileScale.y) + m_offset.y;

		m_tile.setPosition(sf::Vector2f(m_snapPosition.x, m_snapPosition.y));
		m_isMouseOnGrid = true;
	}
	else {
		m_tile.setPosition(mousePosition);
		m_isMouseOnGrid = false;
	}
}

void MouseTile::Draw(sf::RenderWindow& window){
	window.draw(m_tile);
}

bool MouseTile::isMouseClickedOnTile( sf::Vector2f& tilePosition, sf::Vector2i& gridPosition) const{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&& m_isMouseOnGrid) {
		tilePosition = sf::Vector2f(m_snapPosition);
		gridPosition = sf::Vector2i(m_tileIndex);
		return true;
	}
	return false;
}



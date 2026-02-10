#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(const sf::Vector2i& tileSize,
	const sf::Vector2f& tileScale,
	const sf::Vector2f offset):
	m_tile(m_tileSheet),
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
	m_tile.setTextureRect({ {11 * m_tileSize.x,0}, { m_tileSize.x,m_tileSize.y } });
	m_tile.setScale(sf::Vector2f(m_tileScale.x, m_tileScale.y));
	}
	else {
		std::cout << "not working" << std::endl;
	}


}

void MouseTile::Update(float deltatime, const sf::Vector2f& mousePosition){


	bool snapCondition = mousePosition.x - m_offset.x < 10 * (m_tileSize.x * m_tileScale.x) 
		&& mousePosition.y - m_offset.y < 5 * (m_tileSize.y * m_tileScale.y)
		&& mousePosition.x > m_offset.x
		&& mousePosition.y > m_offset.y;

	if (snapCondition) {
	
	//dived the mousePositions by cellSize and scale store it in an int variable and multiply by cellsize and scale
		 tileIndex.x = (mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
		 tileIndex.y = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);

		 snapPosition.x = tileIndex.x * (m_tileSize.x * m_tileScale.x)+m_offset.x;
		 snapPosition.y = tileIndex.y * (m_tileSize.y * m_tileScale.y)+m_offset.y;

		m_tile.setPosition(sf::Vector2f(snapPosition.x, snapPosition.y));
		m_isMouseOnGrid=true;
	}
	else {
		m_tile.setPosition(mousePosition);
		m_isMouseOnGrid = false;
	}


}

void MouseTile::Draw(sf::RenderWindow& window){
	window.draw(m_tile);
}

bool MouseTile::isMouseClickedOnTile( sf::Vector2f& tilePosition) const{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&& m_isMouseOnGrid) {
		tilePosition = sf::Vector2f(tileIndex);
		return true;
	}
	return false;
}

#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(const sf::Vector2i& tileSize, const sf::Vector2f& tileScale):m_tile(m_tileSheet),m_tileSize(tileSize),m_tileScale(tileScale){

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


	bool snapCondition = mousePosition.x - 100 < 10 * (m_tileSize.x * m_tileScale.x) 
		&& mousePosition.y - 50 < 5 * (m_tileSize.y * m_tileScale.y) 
		&& mousePosition.x > 100 
		&& mousePosition.y > 50;

	if (snapCondition) {
	
	//dived the mousePositions by cellSize and scale store it in an int variable and multiply by cellsize and scale
		const int intX = (mousePosition.x-100) / (m_tileSize.x * m_tileScale.x);
		const int intY = (mousePosition.y-50) / (m_tileSize.y * m_tileScale.y);

		const int snapPosix = intX * (m_tileSize.x * m_tileScale.x);
		const int snapPosiy = intY * (m_tileSize.y * m_tileScale.y);

		m_tile.setPosition(sf::Vector2f(snapPosix+100, snapPosiy+50));
	}
	else {
		m_tile.setPosition(mousePosition);
	}


}

void MouseTile::Draw(sf::RenderWindow& window){
	window.draw(m_tile);
}

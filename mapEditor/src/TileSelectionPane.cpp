#include "TileSelectionPane.h"
#include <iostream>

TileSelectionPane::TileSelectionPane() :
	m_totalTiles(0, 0),
	m_cellSize(16, 16),
	m_scale(2, 2),
	m_panePosition(1400, 100),
	m_tileGap(1.2f, 1.2f),
	m_gridColumns(10),
	m_tileIDs(nullptr)
{
	
}

TileSelectionPane::~TileSelectionPane()
{
}

void TileSelectionPane::Initialize() {
	sf::Image tileImage;

	
	if (tileImage.loadFromFile("assets/world/prison/tilesheet.png")) {

		
		m_tileTexture.loadFromImage(tileImage);

		m_totalTiles.x = tileImage.getSize().x / m_cellSize.x;
		m_totalTiles.y = tileImage.getSize().y / m_cellSize.y;

		m_tileIDs = new int[m_totalTiles.x * m_totalTiles.y];
	

		int validTileCount = 0; 
		m_tileSprites.clear();  

		for (int y = 0; y < m_totalTiles.y; y++) {
			for (int x = 0; x < m_totalTiles.x; x++) {
				int i = x + y * m_totalTiles.x;
				
				bool isEmpty = true;
				for (int py = 0; py < m_cellSize.y; py++) {
					for (int px = 0; px < m_cellSize.x; px++) {
						sf::Color pixelColor = tileImage.getPixel(sf::Vector2u(x * m_cellSize.x + px, y * m_cellSize.y + py));
						if (pixelColor.a > 0) {
							isEmpty = false;
							break;
						}
					}
					if (!isEmpty) break;
				}

				if (!isEmpty) {
					sf::Sprite newSprite(m_tileTexture);

					m_tileIDs[validTileCount] = i;
					
					newSprite.setTextureRect(sf::IntRect({ x * m_cellSize.x, y * m_cellSize.y }, { m_cellSize.x, m_cellSize.y }));
					newSprite.setScale(sf::Vector2f(m_scale));

					
					int gridX = validTileCount % m_gridColumns;
					int gridY = validTileCount / m_gridColumns;

					newSprite.setPosition(sf::Vector2f(
						m_panePosition.x + gridX * m_cellSize.x * m_scale.x * m_tileGap.x,
						m_panePosition.y + gridY * m_cellSize.y * m_scale.y * m_tileGap.y
					));

					m_tileSprites.push_back(newSprite);
					validTileCount++;
				}
			}
		}
	}
	else {
		std::cout << "file not loaded" << std::endl;
	}

}

void TileSelectionPane::Load(){
	
	

}

void TileSelectionPane::Update(sf::Vector2f& mousePosition){
	m_mousePosition = &mousePosition;
	m_mouseIsRelesed = false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !m_mouseIsRelesed) {
		m_mouseIsPressed = true;
	}
	else {
		if (m_mouseIsPressed) {
			m_mouseIsRelesed = true;
			m_mouseIsPressed = false;
		}
	}
}

void TileSelectionPane::Draw(sf::RenderWindow& window) {
	
	for (size_t i = 0; i < m_tileSprites.size(); i++) {
		window.draw(m_tileSprites[i]);
	}
}


int TileSelectionPane::IsPressed() {

	if (m_mouseIsRelesed) {

		for (size_t i = 0; i < m_tileSprites.size(); i++) {
			

			if (m_tileSprites[i].getGlobalBounds().contains(*m_mousePosition))
			{


				return m_tileIDs[i];
			}
		}
	}

	return -1;
}
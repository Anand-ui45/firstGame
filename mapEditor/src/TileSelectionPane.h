#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class TileSelectionPane {
private:
	std::vector<sf::Sprite> m_tileSprites;
	sf::Texture m_tileTexture;
	sf::Vector2i m_cellSize;
	sf::Vector2i m_scale;
	sf::Vector2i m_totalTiles;
	sf::Vector2i m_panePosition;
	sf::Vector2f m_tileGap;
	int m_gridColumns; // Determines how many tiles wide the selection pane is
	int* m_tileIDs;

	const sf::Vector2f* m_mousePosition;

	bool m_mouseIsPressed;
	bool m_mouseIsRelesed;

public:
	TileSelectionPane();
	~TileSelectionPane();

	void Initialize();
	void Load();
	void Update(sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
	int IsPressed();
};
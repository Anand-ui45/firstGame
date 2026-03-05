#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"


class MouseTile{

private:
	sf::Texture m_tileSheet;
	sf::Sprite m_tile;
	sf::Vector2i m_tileIndex;
	sf::Vector2i m_tileSize;
	sf::Vector2f m_snapPosition;
	sf::Vector2f m_tileScale;
	sf::Vector2f m_offset;
	bool m_isMouseOnGrid;

	int m_currentTileID;

	const Grid& m_grid;

public:
	MouseTile(const Grid& grid, const sf::Vector2i& tileSize, const sf::Vector2f& tileScale,const sf::Vector2f offset);
	~MouseTile();
	void Initialize();
	void Load();
	void Update(float deltatime,const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);

	bool isMouseClickedOnTile(sf::Vector2f& tilePosition, sf::Vector2i& gridPosition) const;
	inline const sf::Sprite& GetTileSprite()const { return m_tile; }
	inline int GetCurrentTileID()const { return m_currentTileID; }

};



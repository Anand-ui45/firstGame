#pragma once
#include <SFML/Graphics.hpp>


class MouseTile{

private:
	sf::Texture m_tileSheet;
	sf::Sprite m_tile;
	sf::Vector2i tileIndex;
	sf::Vector2i m_tileSize;
	sf::Vector2f snapPosition;
	sf::Vector2f m_tileScale;
	sf::Vector2f m_offset;
	bool m_isMouseOnGrid;

public:
	MouseTile(const sf::Vector2i& tileSize, const sf::Vector2f& tileScale,const sf::Vector2f offset);
	~MouseTile();
	void Initialize();
	void Load();
	void Update(float deltatime,const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);

	bool isMouseClickedOnTile(sf::Vector2f& tilePosition) const;

};



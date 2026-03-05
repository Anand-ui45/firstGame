#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "MouseTile.h"
#define MAP_SIZE 50

class Map{
private:
	std::vector<sf::Sprite> m_mapSprties;
	sf::Texture m_tileTexture;
	const MouseTile& m_mouseTile;
	const Grid& m_grid;
	int* m_tileIDs;


public:
	Map(const Grid& grid, const MouseTile& mouseTile);
	~Map();
	void Load();
	void Initialize();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);

	inline const int* GetTileIDs() const { return m_tileIDs; }
};


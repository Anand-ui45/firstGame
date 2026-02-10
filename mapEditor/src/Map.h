#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#define MAP_SIZE 50

class Map{
private:
	std::vector<sf::Sprite> m_mapSprties;
	sf::Texture m_tileTexture;
	MouseTile& m_mouseTile;


public:
	Map( MouseTile& mouseTile);
	~Map();
	void Load();
	void Intailize();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);

};


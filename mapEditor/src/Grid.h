
#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"





class Grid
{
	private:
		int m_lineThicknes;

		sf::RectangleShape* m_hLine;
		sf::RectangleShape* m_vLine;

		sf::Vector2f m_position;

		sf::Vector2i m_scale;
		sf::Vector2i m_cellSize;
		sf::Vector2i m_totalCells;
		sf::Vector2i m_totalLines;

		sf::Color m_color;

	public:
		Grid(const sf::Vector2f& position,
			const sf::Vector2i& cellSize,
			const sf::Vector2i& totalcells,
			const sf::Vector2i& scale,
			const sf::Color& color,
			int lineThicknes);
		~Grid();
		void Initialize();
		void Load();
		void Update(float deltatime);
		void Draw(sf::RenderWindow& window);

};


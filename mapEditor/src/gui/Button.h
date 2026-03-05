#pragma once
#include <SFML/Graphics.hpp>

namespace gui {
	class Button {
	private:
		sf::Sprite m_buttonSprite;
		sf::Texture m_buttonTexture;
		const sf::Vector2f& m_position;
		const sf::Vector2f& m_scale;
		const sf::Vector2f* m_mousePosition;

		bool m_mouseIsPressed;
		bool m_mouseIsRelesed;

	public:
		Button(const sf::Vector2f& position, const sf::Vector2f& scale);
		~Button();

		void Initialize();
		void Load();
		void Update(double deltatime, sf::Vector2f& mousePosition);
		void Draw(sf::RenderWindow& window);

		bool IsPressed();

	};
}

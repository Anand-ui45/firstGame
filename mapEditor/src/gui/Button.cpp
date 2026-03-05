#include "Button.h"
#include <iostream>

namespace gui {
	Button::Button(const sf::Vector2f& position, const sf::Vector2f& scale): 
		m_buttonSprite(m_buttonTexture),
		m_position(position),
		m_scale(scale),
		m_mousePosition(nullptr),
	    m_mouseIsPressed(false),
	    m_mouseIsRelesed(false){
	}
	Button::~Button()
	{
	}
	void Button::Initialize()
	{
	}
	void Button::Load(){
		if (m_buttonTexture.loadFromFile("assets/gui/button.png")) {
			m_buttonSprite.setTexture(m_buttonTexture, true);
			m_buttonSprite.setPosition(m_position);
			m_buttonSprite.setScale(m_scale);
		}
	}


	void Button::Update(double deltatime, sf::Vector2f& mousePosition){
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


	void Button::Draw(sf::RenderWindow& window){
		window.draw(m_buttonSprite);
	}
	bool Button::IsPressed(){

		if (m_mouseIsRelesed) {

			
			const sf::Vector2u& size = m_buttonSprite.getTexture().getSize();

			sf::Vector2f endPosition(m_position.x + (size.x * m_scale.x), m_position.y + (size.y * m_scale.y));

			if ((m_mousePosition->x >= m_position.x && m_mousePosition->x <= endPosition.x) &&
				(m_mousePosition->y >= m_position.y && m_mousePosition->y <= endPosition.y))
			{

				
				return true;
			}
		}

		return false;
	}
}

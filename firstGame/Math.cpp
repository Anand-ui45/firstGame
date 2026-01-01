#include "Math.h"

sf::Vector2f Math::Normalize(sf::Vector2f dir) {
	float m = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	sf::Vector2f normalizedVector;

	normalizedVector.x = dir.x / m;
	normalizedVector.y = dir.y / m;

	return normalizedVector;

}
bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2) {

	if ((rect1.position.x + rect1.size.x > rect2.position.x &&
		rect2.position.x + rect2.size.x > rect1.position.x)
		&&
		(rect1.position.y + rect1.size.y > rect2.position.y &&
			rect2.position.y + rect2.size.y > rect1.position.y))
		return true;


	return false;
};

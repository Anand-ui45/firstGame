#include "Math.h"

sf::Vector2f Math::Normalize(sf::Vector2f dir) {
	float m = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	sf::Vector2f normalizedVector;

	normalizedVector.x = dir.x / m;
	normalizedVector.y = dir.y / m;

	return normalizedVector;

};

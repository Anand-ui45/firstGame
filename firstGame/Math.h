#pragma once
#include <SFML/Graphics.hpp>

class Math{


public:
static sf::Vector2f Normalize(sf::Vector2f dir);

static bool DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
};


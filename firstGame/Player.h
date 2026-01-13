#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"


class Player{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<Bullet> bullets;
	float maxFireRate;
	float fireRateTimer;

	float playerSpeed;

	sf::RectangleShape boundingRectangel;

	sf::Vector2i size;
	
public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(float deltatime,Skeleton& skeleton, sf::Vector2f &mousPosition);
	void Draw(sf::RenderWindow& window);
};


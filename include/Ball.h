#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Ball : public Entity {
public:
	Ball();
	Ball(float rad);
	void update(sf::Time deltaTime);

	bool outOfBounds();
	bool checkCollisionWithPlayer();
	bool checkCollisionWithBorder();

	void waitForStart();
	void reset();

private:
	float m_rad{};
};
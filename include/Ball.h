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

	void start();
	void reset();

	void increaseVel(float vel);
	void setIsMoving(bool moving) { m_isMoving = moving; }
	bool isMoving() { return m_isMoving; }
private:
	float m_rad{};
	const float MAX_VELOCITY{ 800.f };
	bool m_isMoving{};
};


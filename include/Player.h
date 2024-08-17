#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player(const float width, const float height);
	~Player();
	void update(sf::Time deltaTime);

	int getScore() { return m_score; }
	void updateScore() { m_score++; }
	void setScore(int score) { m_score = score; }

	void setPlayer(int player) { m_player = player; }
	int getPlayer() { return m_player; }

private:
	int m_score{};
	int m_player{1};
};

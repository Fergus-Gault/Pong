#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class Pong {
public:
	Pong();
	~Pong();
	void run();
	const sf::Vector2u getWindowSize() { return m_window.getSize(); }
	sf::RenderWindow& getWindow() { return m_window; }
	void reset();

private:
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void startGame();
};

extern Pong pong;
extern Player player1;
extern Player player2;
extern Ball ball;
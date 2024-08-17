#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Text.h"

class Pong {
public:
	Pong();
	~Pong();
	void run();
	const sf::Vector2u getWindowSize() { return m_window.getSize(); }
	sf::RenderWindow& getWindow() { return m_window; }
	void reset();

	Text player1Score() { return m_player1Score; }
	Text player2Score() { return m_player2Score; }

private:
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	sf::Font m_font;
	Text m_player1Score{};
	Text m_player2Score{};
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void startGame();
};

extern Pong pong;
extern Player player1;
extern Player player2;
extern Ball ball;

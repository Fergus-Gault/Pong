#include "Pong.h"
#include "Player.h"
#include "Ball.h"
#include "Entity.h"

Pong::Pong() : m_window(sf::VideoMode(800, 600), "Pong") {}

Pong::~Pong() {}

void Pong::processEvents() {

	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
		// Resize view if window resized
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
			m_window.setView(sf::View(visibleArea));
		}
	}
}
Player player1(20.f, 120.f);
Player player2(20.f, 120.f);
Ball ball(10.f);

void Pong::run() {

	startGame();

	sf::Clock clock;
	while (m_window.isOpen()) {
		processEvents();
		update(clock.restart());
		render();
	}
}

void Pong::update(sf::Time deltaTime) {
	player1.update(deltaTime);
	player2.update(deltaTime);
	ball.update(deltaTime);
}

void Pong::render() {


	m_window.clear();

	player1.render();
	player2.render();
	ball.render();

	m_window.display();
}


void Pong::reset() {
	player1.setPos(10.f, m_window.getSize().y / 2);
	player2.setPos(m_window.getSize().x - player2.getWidth() - 10.f, m_window.getSize().y / 2);
	ball.reset();
}

void Pong::startGame() {
	player1.setPlayer(1);
	player1.moveEntity(10.f, m_window.getSize().y / 2);
	player1.setVelocity(0.f, 300.f);


	player2.setPlayer(2);
	player2.moveEntity(m_window.getSize().x - player2.getWidth() - 10.f, m_window.getSize().y / 2);
	player2.setVelocity(0.f, 300.f);

	ball.setPos(m_window.getSize().x / 2, m_window.getSize().y / 2);
	ball.setVelocity(0, 0);

}


Pong pong{};

int main() {
	pong.run();

	return EXIT_SUCCESS;
}
#include "Player.h"
#include <iostream>

Player::Player(const float width, const float height) : Entity(width, height) {};

void Player::update(sf::Time deltaTime) {
	if (getPlayer() == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			move(0.f, -100.f * deltaTime.asSeconds() * getVelocity());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			move(0.f, 100.f * deltaTime.asSeconds() * getVelocity());
		}
	}
	else if (getPlayer() == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			move(0.f, -100.f * deltaTime.asSeconds() * getVelocity());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			move(0.f, 100.f * deltaTime.asSeconds() * getVelocity());
		}
	}
}
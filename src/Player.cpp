#include "Player.h"
#include <iostream>

Player::Player(const float width, const float height) : Entity(width, height) {};
Player::~Player() {};

void Player::update(sf::Time deltaTime) {
	if (getPlayer() == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			moveEntity(0.f, deltaTime.asSeconds() * -getVelocity().y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			moveEntity(0.f, deltaTime.asSeconds() * getVelocity().y);
		}
	}
	else if (getPlayer() == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			moveEntity(0.f, deltaTime.asSeconds() * -getVelocity().y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			moveEntity(0.f, deltaTime.asSeconds() * getVelocity().y);
		}
	}
}
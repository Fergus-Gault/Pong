#include "Ball.h"
#include "Pong.h"
#include <math.h>
#include <iostream>


Ball::Ball() {};
Ball::Ball(float rad) : Entity(rad, rad) {}

bool Ball::outOfBounds() {
	if (getPos().x > pong.getWindow().getSize().x || getPos().x < 0) {
		std::cout << "Out of bounds\n";
		return true;
	}
	return false;
}

bool Ball::checkCollisionWithBorder() {
	if (getPos().y > pong.getWindow().getSize().y-getWidth() || getPos().y < 0) {
		return true;
	}
	return false;
}

bool Ball::checkCollisionWithPlayer() { // Check collision with either player
	if (getRect().getGlobalBounds().intersects(player1.getRect().getGlobalBounds())) {
		return true;
	}
	else if (getRect().getGlobalBounds().intersects(player2.getRect().getGlobalBounds())) {
		return true;
	}
	return false;
}

void Ball::reset() {
	setPos(pong.getWindow().getSize().x / 2, pong.getWindow().getSize().y / 2);
	setVelocity(0, 0);

}

void Ball::update(sf::Time deltaTime) {
	if (checkCollisionWithPlayer()) {
		setVelocity(-getVelocity().x, getVelocity().y);
	}
	if (checkCollisionWithBorder()) {
		setVelocity(getVelocity().x, -getVelocity().y);
	}
	if (outOfBounds()) {
		pong.reset();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		setVelocity(400, 200);
	}
	moveEntity(getVelocity().x * deltaTime.asSeconds(), getVelocity().y * deltaTime.asSeconds());
}

void Ball::waitForStart() {
	while (true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			setVelocity(400, 200);
			return;
		}
	}
}
#include "Ball.h"
#include "Pong.h"
#include <math.h>
#include <iostream>
#include <random>


Ball::Ball() {};
Ball::Ball(float rad) : Entity(rad, rad) {}

bool Ball::outOfBounds() {
	if (getPos().x > pong.getWindow().getSize().x || getPos().x < 0) {
		if (getPos().x > pong.getWindow().getSize().x) {
			player1.setScore(player1.getScore() + 1);
		}
		else if (getPos().x < 0) {
			player2.setScore(player2.getScore() + 1);
		}
		
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
	setIsMoving(false);
	setPos(pong.getWindow().getSize().x / 2, pong.getWindow().getSize().y / 2);
	setVelocity(0, 0);
}

void Ball::update(sf::Time deltaTime) {
	if (checkCollisionWithPlayer()) {
		setVelocity(-(getVelocity().x), getVelocity().y);
		increaseVel(10.f);
	}
	if (checkCollisionWithBorder()) {
		setVelocity(getVelocity().x, -getVelocity().y);
	}
	if (outOfBounds()) {
		pong.reset();
	}

	moveEntity(getVelocity().x * deltaTime.asSeconds(), getVelocity().y * deltaTime.asSeconds());
}

void Ball::start() {
	std::random_device rd;
	std::mt19937 gen(rd());

	// Distribution to choose between -1 and 1
	std::uniform_int_distribution<> sign_selector(0, 1);

	// Generate random number for range -300 to -50
	std::uniform_int_distribution<> dist1(-300, -50);

	// Generate random number for range 50 to 300
	std::uniform_int_distribution<> dist2(50, 300);

	// Choose the range
	int choice = sign_selector(gen);

	int random_number;
	if (choice == 0) {
		random_number = dist1(gen); // Choose from -300 to -50
	}
	else {
		random_number = dist2(gen); // Choose from 50 to 300
	}

	int sign = sign_selector(gen) == 0 ? -1 : 1;

	setVelocity(sign * 400, random_number);
	
}

void Ball::increaseVel(float vel) {
	if (getVelocity().x < MAX_VELOCITY) {
		if (getVelocity().x > 0) {
			setVelocity(getVelocity().x + vel, getVelocity().y);
		}
		else if (getVelocity().x < 0) {
			setVelocity(getVelocity().x - vel, getVelocity().y);
		
		}
		std::cout << getVelocity().x << '\n';
	}
}
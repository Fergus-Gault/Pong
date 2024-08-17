#include "Ball.h"
#include "Pong.h"
#include <math.h>
#include <random>


Ball::Ball() {};
Ball::Ball(float rad) : Entity(rad, rad) {}
Ball::~Ball() {};

bool Ball::outOfBounds() {
	
	if (getPos().x > pong.getWindow().getSize().x) {
		player1.setScore(player1.getScore() + 1); // If out on right side
		return true;
	}
	else if (getPos().x < 0) {
		player2.setScore(player2.getScore() + 1); // If out on left side
		return true;
	}
	return false;
}

bool Ball::checkCollisionWithBorder() {
	if (getPos().y > pong.getWindow().getSize().y-getWidth() || getPos().y < 0) { // Check if collision with top or bottom of screen
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
	setPos(pong.getWindow().getSize().x / 2, pong.getWindow().getSize().y / 2); // Reset to middle of screen
	setVelocity(0, 0);
}

void Ball::update(sf::Time deltaTime) {
	if (checkCollisionWithPlayer()) { // If collision with a player, reverse the velocity on the x-axis
		setVelocity(-(getVelocity().x), getVelocity().y);
		increaseVel(10.f); // Increase the speed of the ball
	}
	if (checkCollisionWithBorder()) { // If collision with the border, reverse the velocity on the y-axis
		setVelocity(getVelocity().x, -getVelocity().y);
	}
	if (outOfBounds()) { // If out of bounds reset the balls position
		pong.reset(); 
	}

	// Move the ball based on new velocity
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

	// Generate a random x and y velocity, either +400 or -400 in x-axis and between -300 to -50 or 50 to 300 in the y-axis
	setVelocity(sign * 400, random_number); 
	
}

void Ball::increaseVel(float vel) {
	if (getVelocity().x < MAX_VELOCITY) { // Increase the velocity on collision with a player
		if (getVelocity().x > 0) {
			setVelocity(getVelocity().x + vel, getVelocity().y);
		}
		else if (getVelocity().x < 0) {
			setVelocity(getVelocity().x - vel, getVelocity().y);
		
		}
	}
}
#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	Entity();
	~Entity();
	Entity(const float width, const float height);
	Entity(const Entity& copy);
	void render();
	void update();

	sf::Vector2f getVelocity() { return m_velocity; }
	void setVelocity(auto x, auto y) { m_velocity = sf::Vector2f(x,y); }

	sf::Vector2f getPos() { return m_rectangle.getPosition(); }
	void setPos(auto x, auto y) { m_rectangle.setPosition(sf::Vector2f(x, y)); }

	void moveEntity(float x, float y) { m_rectangle.move(sf::Vector2f(x, y)); }

	const float getWidth() { return m_width; }

	sf::RectangleShape getRect() { return m_rectangle; }

private:
	sf::RectangleShape m_rectangle{};
	sf::Vector2f m_velocity{};
	float m_width{};
};
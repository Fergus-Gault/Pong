#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	Entity();
	Entity(const float width, const float height);
	Entity(const Entity& copy);
	void render();
	void update();
	bool isSolid() { return m_solid; }
	void setSolid(bool solid) { m_solid = solid; }
	float getVelocity() { return m_velocity; }
	void setVelocity(float velocity) { m_velocity = velocity; }
	sf::Vector2f getPos() { return m_pos; }

	void move(auto x=0, auto y=0) { m_rectangle.move(sf::Vector2f(x, y)); }

	const float getWidth() { return m_width; }

private:
	sf::RectangleShape m_rectangle{};
	float m_velocity{10};
	bool m_solid{};
	sf::Vector2f m_pos{};
	float m_width{};
};
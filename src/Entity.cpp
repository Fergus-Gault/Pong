#include "Pong.h"
#include "Entity.h"
#include <iostream>

Entity::Entity(){};

Entity::Entity(const float width, const float height)
	: m_rectangle(sf::Vector2f(width, height))
	, m_width{ width }
{
	m_rectangle.setFillColor(sf::Color(255, 255, 255));
	setSolid(false);
};

Entity::Entity(const Entity& copy): m_rectangle{copy.m_rectangle}
{}

void Entity::render() {
	pong.getWindow().draw(m_rectangle);
}
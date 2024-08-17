#include "Text.h"
#include "Pong.h"

Text::Text() {}

void Text::setFont(const sf::Font& font) {
    m_text.setFont(font); 
}

void Text::render() {
    pong.getWindow().draw(m_text);
}

void Text::update(int score) {
    m_text.setString(std::to_string(score));
}
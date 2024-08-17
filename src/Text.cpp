#include "Text.h"
#include "Pong.h"

Text::Text() {}

Text::~Text() {}

void Text::setFont(const sf::Font& font) {
    m_text.setFont(font); 
}

void Text::render() {
    pong.getWindow().draw(m_text); // Draw the text to the screen
}

void Text::update(int score) {
    m_text.setString(std::to_string(score)); // Update the score
}
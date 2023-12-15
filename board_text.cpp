#include"board_text.hpp"

sf::Text Text::PlayerOneScoreText;
sf::Text Text::PlayerTwoScoreText;
sf::Text Text::PlayerOneName;
sf::Text Text::PlayerTwoName;

Text::Text() {
    font.loadFromFile("includes/fonts/TGM.ttf");
    setText(PlayerOneScoreText, "Score : 0", sf::Vector2f(760, 210), 1.0f);
    setText(PlayerTwoScoreText, "Score : 0", sf::Vector2f(760, 310), 1.0f);
    setText(PlayerOneName, "Player 1", sf::Vector2f(730, 150), 1.2f);
    setText(PlayerTwoName, "Player 2", sf::Vector2f(730, 250), 1.2f);
}

void Text::setText(sf::Text& text, const std::string& content, const sf::Vector2f& position, float scale) {
    text.setFont(font);
    text.setString(content);
    text.setPosition(position);
    text.setScale(sf::Vector2f(scale, scale));
}
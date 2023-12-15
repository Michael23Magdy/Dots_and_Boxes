#include <SFML/Graphics.hpp>
#include<vector>
#ifndef BOARD_TEXT_H_
#define BOARD_TEXT_H_
static sf::Font font ;
struct Text {
    static sf::Text PlayerOneScoreText ;
    static sf::Text PlayerTwoScoreText ;
    static sf::Text PlayerOneName ;
    static sf::Text PlayerTwoName ; 

    Text() ;

    void setText(sf::Text &text ,const std::string& content, const sf::Vector2f& position, float scale) ;
} ;
#endif
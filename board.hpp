#include"colors.hpp"
#include<vector>
#ifndef BOARD_H_
#define BOARD_H_

struct Board
{
    sf::RenderWindow &window ;
    int boxesCnt ;
    int dotsCnt ;
    float dotsDistance ;

    static const float dotsRadius ;
    static const float lineThickness ;

    std::vector<sf::RectangleShape> horizontaLineProperties;
    std::vector<sf::RectangleShape> verticalLineProperties;
    std::vector<sf::RectangleShape> boxesProperties;
    std::vector<sf::CircleShape> dotsProperties;

    Board(sf::RenderWindow &window_,int boxesCnt_) ;

    void setVerticalLinesProberties();
    void setHorizontalLinesProberties();
    void setDotsProberties() ;
    void setBoxesProberties() ;
    void initializeBoard() ;
};

#endif
#include <SFML/Graphics.hpp>
#ifndef SHAPES_H_
#define SHAPES_H_

struct Line {
    sf::RectangleShape shape ;
    bool isDrawn ;

    Line(int &xCor,int &yCor,int &xLength,int &yLength) ;

    bool contains(int &x,int &y) ;
    void setSize(int &xLength,int &yLength) ;
    void setColour(sf::Color &colour) ;
    void setPosition(int &xCor,int &yCor) ;

} ;
#endif
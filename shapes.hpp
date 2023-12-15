#include <SFML/Graphics.hpp>
#ifndef SHAPES_H_
#define SHAPES_H_

struct Line {
    sf::RectangleShape shape ;
    bool isDrawn ;

    Line(int &xCor,int &yCor,int &xLength,int &yLength) ;

    bool contains(const int &x,const int &y) ;
    void setSize(const int &xLength,const int &yLength) ;
    void setColour(sf::Color &colour) ;
    void setPosition(const int &xCor,const int &yCor) ;

} ;
#endif
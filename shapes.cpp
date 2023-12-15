#include"shapes.hpp"


Line::Line(){ 
    isDrawn = false ;
}

bool Line::contains(const int &x,const int &y) {
    return shape.getGlobalBounds().contains(x,y) ;
}
void Line::setColour(sf::Color &colour) {
    shape.setFillColor(colour) ;
}
void Line::setSize(const int &xLength,const int &yLength) {
    shape.setSize(sf::Vector2f(xLength,yLength)) ;
}
void Line::setPosition(const int &xCor,const int &yCor) {
    shape.setPosition(sf::Vector2f(xCor,yCor)) ;
}

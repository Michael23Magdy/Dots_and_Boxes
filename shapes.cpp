#include"shapes.hpp"


Line::Line(int &xCor,int &yCor,int &xLength,int &yLength){
    setPosition(xCor,yCor) ;
    setSize(xLength,yLength);
    isDrawn = false ;
}

bool Line::contains(int &x,int &y) {
    return shape.getGlobalBounds().contains(x,y) ;
}
void Line::setColour(sf::Color &colour) {
    shape.setFillColor(colour) ;
}
void Line::setSize(int &xLength,int &yLength) {
    shape.setSize(sf::Vector2f(xLength,yLength)) ;
}
void Line::setPosition(int &xCor,int &yCor) {
    shape.setPosition(sf::Vector2f(xCor,yCor)) ;
}

#include"board.hpp"

const float Board::dotsRadius = 20;
const float Board::lineThickness = 15;

Board::Board(sf::RenderWindow &window_,int boxesCnt_) 
    : window(window_) , 
      boxesCnt(boxesCnt_) ,
      dotsCnt(boxesCnt + 1) ,
      horizontaLineProperties(boxesCnt * (boxesCnt + 1)),
      verticalLineProperties(boxesCnt * (boxesCnt + 1)) ,
      boxesProperties(boxesCnt * boxesCnt) ,
      dotsProperties(dotsCnt * dotsCnt) ,
      dotsDistance(600.0f / boxesCnt + 5)
{

}

void Board::initializeBoard()
{
    setBoxesProberties();
    setDotsProberties();
    setHorizontalLinesProberties();
    setVerticalLinesProberties();
}

void Board::setHorizontalLinesProberties(){
    for (int i = 0; i < boxesCnt + 1; i++)
    {
        for (int j = 0; j < boxesCnt; j++)
        {
            horizontaLineProperties[i * boxesCnt + j].setPosition(55 + 2 * dotsRadius + j * dotsDistance,
                                                             60 - lineThickness / 2 + dotsRadius + i * dotsDistance);
            horizontaLineProperties[i * boxesCnt + j].setColour(blackColour);
            horizontaLineProperties[i * boxesCnt + j].setSize(dotsDistance - 2 * dotsRadius + 10, lineThickness);
        }
    }
}
void Board::setVerticalLinesProberties(){
    for (int i = 0; i < boxesCnt; i++)
    {
        for (int j = 0; j < boxesCnt + 1; j++)
        {
            verticalLineProperties[i*dotsCnt + j].setPosition(60 + lineThickness / 2 + dotsRadius + j * dotsDistance,
                                                                   55 + 2 * dotsRadius + i * dotsDistance);
            verticalLineProperties[i*dotsCnt + j].setColour(blackColour);
            verticalLineProperties[i*dotsCnt + j].setSize(dotsDistance - 2 * dotsRadius + 10, lineThickness);
            verticalLineProperties[i*dotsCnt + j].shape.rotate(90.f);
        }
    }
}

void Board::setBoxesProberties(){
    for (int i = 0; i < boxesCnt; i++)
    {
        for (int j = 0; j < boxesCnt; j++)
        {
            boxesProperties[i * boxesCnt + j].setPosition(sf::Vector2f(55 + 2 * dotsRadius + j * dotsDistance - 10,
                                                             55 + 2 * dotsRadius + i * dotsDistance - 10));
            boxesProperties[i * boxesCnt + j].setFillColor(sf::Color(0, 0, 0, 0));
            boxesProperties[i * boxesCnt + j].setSize(sf::Vector2f(dotsDistance - 2 * dotsRadius + 32, dotsDistance - 2 * dotsRadius + 32));
        }
    }
}

void Board::setDotsProberties(){
    for (int i = 0; i < dotsCnt; i++)
    {
        for (int j = 0; j < dotsCnt; j++)
        {
            dotsProperties[i * dotsCnt + j].setRadius(dotsRadius);
            dotsProperties[i * dotsCnt + j].setPosition(sf::Vector2f(60 + j * dotsDistance, 60 + i * dotsDistance));
            dotsProperties[i * dotsCnt + j].setFillColor(whiteColour);
            dotsProperties[i * dotsCnt + j].setPointCount(100);
        }
    }
}

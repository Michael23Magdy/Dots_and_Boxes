#include "board.hpp"
#include <SFML/Graphics.hpp>
#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_

struct GameLogic {
    sf::RenderWindow &window ;
    Board gameBoard;

    int playerScores[2];
    bool isPlayer2Turn;
    bool isBoxClosed;

    int boxesCnt ;
    int dotsCnt ;

    GameLogic(sf::RenderWindow &window_, int boxesCnt_);
    void checkAndUpdateLines(sf::Event &event ,std::vector<Line> &lineProperties, int &xPos,int &yPos,const int &lineType) ;
    void checkAndUpdateHorizontalLines(sf::Event &event , int &xPos,int &yPos);
    void checkAndUpdateVerticalLines(sf::Event &event , int &xPos,int &yPos);
    void run();
};
#endif
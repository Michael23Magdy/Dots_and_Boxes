#include"game_logic.hpp"
#include"colors.hpp"

enum LineType{
    horizontalLine ,
    verticalLine 
} ;

GameLogic::GameLogic(sf::RenderWindow &window_, int boxesCnt_)
    : window(window_) ,
      gameBoard(window_,boxesCnt_) ,
      boxesCnt(boxesCnt_) ,
      dotsCnt(boxesCnt_ + 1)

{
    playerScores[0] = 0;
    playerScores[1] = 0;
    
    isPlayer2Turn = false;
    isBoxClosed = false;
    gameBoard.initializeBoard() ;
}

void GameLogic::checkAndUpdateHorizontalLines(sf::Event &event , int &xPos,int &yPos)   {
    checkAndUpdateLines(event,gameBoard.horizontaLineProperties,xPos,yPos,horizontalLine) ;
    }
void GameLogic::checkAndUpdateVerticalLines(sf::Event &event , int &xPos,int &yPos){
    checkAndUpdateLines(event,gameBoard.verticalLineProperties,xPos,yPos,verticalLine) ;
    }

void GameLogic::checkAndUpdateLines(sf::Event &event ,std::vector<Line> &lineProperties, int &xPos,int &yPos,const int &lineType)  {
    int linesCntInARow = (lineType == horizontalLine ? boxesCnt : boxesCnt + 1) ;
    int linesCntInAColumn = (lineType == horizontalLine ? boxesCnt + 1 : boxesCnt) ;

    for (int i = 0; i < linesCntInAColumn; i++)
        for (int j = 0; j < linesCntInARow; j++)
        {
            int linePos = i * (linesCntInARow) + j;
            if (!lineProperties[linePos].isDrawn)
            {

                if (lineProperties[linePos].contains(xPos, yPos))
                    lineProperties[linePos].setColour(playersLinesColours[isPlayer2Turn]);
                else
                    lineProperties[linePos].setColour(blackColour);

                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {

                        if (lineProperties[linePos].contains(xPos, yPos))
                        {
                            lineProperties[linePos].isDrawn = 1;

                            if (lineType == horizontalLine) 
                                linePos = linePos + linePos/boxesCnt ;
                                
                            for (int i = 0; i < 2; i++)
                            {
                                int tmplinePos = linePos - (lineType == horizontalLine ? i*dotsCnt : i) ;
                                if ((tmplinePos + 1) % dotsCnt == 0
                                    ||tmplinePos >= dotsCnt*boxesCnt ) continue;
                                if (gameBoard.verticalLineProperties[tmplinePos].isDrawn &&
                                    gameBoard.verticalLineProperties[tmplinePos + 1].isDrawn &&
                                    gameBoard.horizontaLineProperties[tmplinePos - tmplinePos / dotsCnt].isDrawn &&
                                    gameBoard.horizontaLineProperties[tmplinePos - tmplinePos / dotsCnt + boxesCnt].isDrawn)
                                {
                                    playerScores[isPlayer2Turn]++;
                                    isBoxClosed = 1;
                                    gameBoard.boxesProperties[tmplinePos - tmplinePos / dotsCnt].setFillColor(playersBoxessColours[isPlayer2Turn]) ;  
                                }
                            }
                            if (!isBoxClosed)
                                isPlayer2Turn = !isPlayer2Turn;
                            else
                            {
                                isBoxClosed = 0;
                                if (!isPlayer2Turn)
                                    gameBoard.text.PlayerOneScoreText.setString("Score: " + std::to_string(playerScores[0]));
                                else
                                    gameBoard.text.PlayerTwoScoreText.setString("Score: " + std::to_string(playerScores[1]));
                            }
                        }
                    }
                }
            }
        }
    }
void GameLogic::run(){
    while (window.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int xPos = pos.x, yPos = pos.y;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            checkAndUpdateHorizontalLines(event,xPos,yPos);
            checkAndUpdateVerticalLines(event,xPos,yPos);
        }
            gameBoard.renderBoard();
    } 
}
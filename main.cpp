// #include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include"colors.hpp"
#include"board.hpp"

int boxesCnt = 4;
int dotsCnt = boxesCnt + 1;

int main()
{

    // Main window
    sf::RenderWindow window(sf::VideoMode(770, 770), "Dots and boxes", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30) ;

    Board gameBoard(window,boxesCnt) ;
    gameBoard.initializeBoard() ;

    bool isHorizontalLineDrawn[boxesCnt * (boxesCnt + 1)] = {0}, isVerticalLineDrawn[boxesCnt * (boxesCnt + 1)] = {0};
    int playerScores[2];
    bool isPlayer2Turn = false;
    bool isBoxClosed = false;

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
            window.clear(grayColour);


            for (int i = 0; i < boxesCnt; i++)
                for (int j = 0; j < boxesCnt; j++)
                    window.draw(gameBoard.boxesProperties[i * boxesCnt + j]);

            for (int i = 0; i < (boxesCnt + 1); i++)
                for (int j = 0; j < boxesCnt; j++)
                {
                    int horizontalLinePos = i * boxesCnt + j;

                    if (!isHorizontalLineDrawn[horizontalLinePos])
                    {

                        if (gameBoard.horizontaLineProperties[horizontalLinePos].getGlobalBounds().contains(xPos, yPos))
                            gameBoard.horizontaLineProperties[horizontalLinePos].setFillColor(playersLinesColours[isPlayer2Turn]);
                        else
                            gameBoard.horizontaLineProperties[horizontalLinePos].setFillColor(blackColour);

                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            if (event.mouseButton.button == sf::Mouse::Left)
                            {

                                if (gameBoard.horizontaLineProperties[horizontalLinePos].getGlobalBounds().contains(xPos, yPos))
                                {
                                    isHorizontalLineDrawn[horizontalLinePos] = 1;
                                    if (horizontalLinePos / boxesCnt)
                                    {
                                        if (isHorizontalLineDrawn[horizontalLinePos - boxesCnt] &&
                                            isVerticalLineDrawn[horizontalLinePos - (dotsCnt - horizontalLinePos / boxesCnt)] &&
                                            isVerticalLineDrawn[horizontalLinePos - (dotsCnt - horizontalLinePos / boxesCnt) + 1])
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[horizontalLinePos-boxesCnt].setFillColor(playersBoxessColours[isPlayer2Turn]) ;
                                        }
                                    }
                                    if (horizontalLinePos / boxesCnt < boxesCnt)
                                    {

                                        if (isHorizontalLineDrawn[horizontalLinePos + boxesCnt] &&
                                            isVerticalLineDrawn[horizontalLinePos + horizontalLinePos / boxesCnt] &&
                                            isVerticalLineDrawn[horizontalLinePos + horizontalLinePos / boxesCnt + 1])
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[horizontalLinePos].setFillColor(playersBoxessColours[isPlayer2Turn]) ;
                                        }
                                    }
                                    if (!isBoxClosed)
                                        isPlayer2Turn = !isPlayer2Turn;
                                    else
                                    {
                                        isBoxClosed = 0;
                                    }
                                }
                            }
                        }
                    }

                    window.draw(gameBoard.horizontaLineProperties[i * boxesCnt + j]);
                }

            for (int i = 0; i < boxesCnt; i++)
                for (int j = 0; j < (boxesCnt + 1); j++)
                {
                    int vertLinePos = i * (boxesCnt + 1) + j;
                    if (!isVerticalLineDrawn[vertLinePos])
                    {

                        if (gameBoard.verticalLineProperties[vertLinePos].getGlobalBounds().contains(xPos, yPos))
                            gameBoard.verticalLineProperties[vertLinePos].setFillColor(playersLinesColours[isPlayer2Turn]);
                        else
                            gameBoard.verticalLineProperties[vertLinePos].setFillColor(blackColour);

                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            if (event.mouseButton.button == sf::Mouse::Left)
                            {

                                if (gameBoard.verticalLineProperties[vertLinePos].getGlobalBounds().contains(xPos, yPos))
                                {
                                    isVerticalLineDrawn[vertLinePos] = 1;

                                    if (vertLinePos % dotsCnt)
                                    {
                                        if (isVerticalLineDrawn[vertLinePos - 1] &&
                                            isHorizontalLineDrawn[vertLinePos - vertLinePos / dotsCnt - 1] &&
                                            isHorizontalLineDrawn[vertLinePos - vertLinePos / dotsCnt - 1 + boxesCnt])
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[vertLinePos - vertLinePos / dotsCnt - 1].setFillColor(playersBoxessColours[isPlayer2Turn]) ;
                                        }
                                    }
                                    if ((vertLinePos + 1) % dotsCnt)
                                    {
                                        if (isVerticalLineDrawn[vertLinePos + 1] &&
                                            isHorizontalLineDrawn[vertLinePos - vertLinePos / dotsCnt] &&
                                            isHorizontalLineDrawn[vertLinePos - vertLinePos / dotsCnt + boxesCnt])
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[vertLinePos - vertLinePos / dotsCnt].setFillColor(playersBoxessColours[isPlayer2Turn]) ;  
                                        }
                                    }
                                    if (!isBoxClosed)
                                        isPlayer2Turn = !isPlayer2Turn;
                                    else
                                    {
                                        isBoxClosed = 0;
                                    }
                                }
                            }
                        }
                    }

                    window.draw(gameBoard.verticalLineProperties[vertLinePos]);
                }

        }
            for (int i = 0; i < dotsCnt; i++)
                for (int j = 0; j < dotsCnt; j++)
                    window.draw(gameBoard.dotsProperties[i * dotsCnt + j]);

            window.display();
    }
    return EXIT_SUCCESS;
}

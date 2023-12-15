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
    sf::RenderWindow window(sf::VideoMode(950, 770), "Dots and boxes", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30) ;

    Board gameBoard(window,boxesCnt) ;
    gameBoard.initializeBoard() ;

    int playerScores[2] = {0,0};
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

                    if (!gameBoard.horizontaLineProperties[horizontalLinePos].isDrawn)
                    {

                        if (gameBoard.horizontaLineProperties[horizontalLinePos].contains(xPos, yPos))
                            gameBoard.horizontaLineProperties[horizontalLinePos].setColour(playersLinesColours[isPlayer2Turn]);
                        else
                            gameBoard.horizontaLineProperties[horizontalLinePos].setColour(blackColour);

                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            if (event.mouseButton.button == sf::Mouse::Left)
                            {

                                if (gameBoard.horizontaLineProperties[horizontalLinePos].contains(xPos, yPos))
                                {
                                    gameBoard.horizontaLineProperties[horizontalLinePos].isDrawn = 1;
                                    if (horizontalLinePos / boxesCnt)
                                    {
                                        if (gameBoard.horizontaLineProperties[horizontalLinePos - boxesCnt].isDrawn &&
                                            gameBoard.verticalLineProperties[horizontalLinePos - (dotsCnt - horizontalLinePos / boxesCnt)].isDrawn &&
                                            gameBoard.verticalLineProperties[horizontalLinePos - (dotsCnt - horizontalLinePos / boxesCnt) + 1].isDrawn)
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[horizontalLinePos-boxesCnt].setFillColor(playersBoxessColours[isPlayer2Turn]) ;
                                        }
                                    }
                                    if (horizontalLinePos / boxesCnt < boxesCnt)
                                    {

                                        if (gameBoard.horizontaLineProperties[horizontalLinePos + boxesCnt].isDrawn &&
                                            gameBoard.verticalLineProperties[horizontalLinePos + horizontalLinePos / boxesCnt].isDrawn &&
                                            gameBoard.verticalLineProperties[horizontalLinePos + horizontalLinePos / boxesCnt + 1].isDrawn)
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
                                        if (!isPlayer2Turn)
                                            gameBoard.text.PlayerOneScoreText.setString("Score: " + std::to_string(playerScores[0]));
                                        else
                                            gameBoard.text.PlayerTwoScoreText.setString("Score: " + std::to_string(playerScores[1]));
                                    }
                                }
                            }
                        }
                    }

                    window.draw(gameBoard.horizontaLineProperties[i * boxesCnt + j].shape);
                }

            for (int i = 0; i < boxesCnt; i++)
                for (int j = 0; j < (boxesCnt + 1); j++)
                {
                    int vertLinePos = i * (boxesCnt + 1) + j;
                    if (!gameBoard.verticalLineProperties[vertLinePos].isDrawn)
                    {

                        if (gameBoard.verticalLineProperties[vertLinePos].contains(xPos, yPos))
                            gameBoard.verticalLineProperties[vertLinePos].setColour(playersLinesColours[isPlayer2Turn]);
                        else
                            gameBoard.verticalLineProperties[vertLinePos].setColour(blackColour);

                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            if (event.mouseButton.button == sf::Mouse::Left)
                            {

                                if (gameBoard.verticalLineProperties[vertLinePos].contains(xPos, yPos))
                                {
                                    gameBoard.verticalLineProperties[vertLinePos].isDrawn = 1;

                                    if (vertLinePos % dotsCnt)
                                    {
                                        if (gameBoard.verticalLineProperties[vertLinePos - 1].isDrawn &&
                                            gameBoard.horizontaLineProperties[vertLinePos - vertLinePos / dotsCnt - 1].isDrawn &&
                                            gameBoard.horizontaLineProperties[vertLinePos - vertLinePos / dotsCnt - 1 + boxesCnt].isDrawn)
                                        {
                                            playerScores[isPlayer2Turn]++;
                                            isBoxClosed = 1;
                                            gameBoard.boxesProperties[vertLinePos - vertLinePos / dotsCnt - 1].setFillColor(playersBoxessColours[isPlayer2Turn]) ;
                                        }
                                    }
                                    if ((vertLinePos + 1) % dotsCnt)
                                    {
                                        if (gameBoard.verticalLineProperties[vertLinePos + 1].isDrawn &&
                                            gameBoard.horizontaLineProperties[vertLinePos - vertLinePos / dotsCnt].isDrawn &&
                                            gameBoard.horizontaLineProperties[vertLinePos - vertLinePos / dotsCnt + boxesCnt].isDrawn)
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
                                        if (!isPlayer2Turn)
                                            gameBoard.text.PlayerOneScoreText.setString("Score: " + std::to_string(playerScores[0]));
                                        else
                                            gameBoard.text.PlayerTwoScoreText.setString("Score: " + std::to_string(playerScores[1]));
                                    }
                                }
                            }
                        }
                    }

                    window.draw(gameBoard.verticalLineProperties[vertLinePos].shape);
                }

            window.draw(gameBoard.text.PlayerOneScoreText);
            window.draw(gameBoard.text.PlayerOneName);

            window.draw(gameBoard.text.PlayerTwoScoreText);
            window.draw(gameBoard.text.PlayerTwoName);
        }
            for (int i = 0; i < dotsCnt; i++)
                for (int j = 0; j < dotsCnt; j++)
                    window.draw(gameBoard.dotsProperties[i * dotsCnt + j]);
            window.display();
    }
    return EXIT_SUCCESS;
}

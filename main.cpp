#include <SFML/Graphics.hpp>

#include"game_logic.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(950, 770), "Dots and boxes", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30) ;

    GameLogic dotsAndBoxesGame(window,5) ;
    dotsAndBoxesGame.run() ;

    return EXIT_SUCCESS;
}

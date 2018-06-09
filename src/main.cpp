#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

int main()
{
    feg::TextureManager tm;
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Fight Epitech Grades");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear(sf::Color::White);
            window.display();
        }
    }
    return (0);
}
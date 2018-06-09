#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Crate.hpp"

int main()
{
    feg::TextureManager tm;
    feg::Crate crate(tm.GetTexture("res/WhiteSquare.png"));
    crate.SetColor(sf::Color(139, 69, 19));
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Fight Epitech Grades");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear(sf::Color::White);
            crate.Update(window);
            window.display();
        }
    }
    return (0);
}
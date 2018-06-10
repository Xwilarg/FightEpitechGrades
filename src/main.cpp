#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Crate.hpp"
#include "Scene.hpp"

int main()
{
    constexpr unsigned int xWin = 1200, yWin = 600;
    feg::TextureManager tm;
    feg::Scene mainScene;
    mainScene.AddGameObject<feg::Crate>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetColor(sf::Color(139, 69, 19));
    mainScene.AddGameObject<feg::GameObject>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetPosition(sf::Vector2f(0.f, yWinl))->SetScale(sf::Vector2f(xWin / 50.f, 1.f));
    sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Fight Epitech Grades");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        mainScene.Update(window);
        window.display();
    }
    return (0);
}
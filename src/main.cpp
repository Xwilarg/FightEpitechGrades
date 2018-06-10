#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Crate.hpp"
#include "Scene.hpp"
#include "Player.hpp"

int main()
{
    constexpr unsigned int xWin = 1200, yWin = 600;
    feg::TextureManager tm;
    feg::Scene mainScene;
    mainScene.AddGameObject<feg::Crate>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetColor(sf::Color(139, 69, 19))->SetPosition(sf::Vector2f(350.f, 0.f));
    mainScene.AddGameObject<feg::GameObject>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetPosition(sf::Vector2f(0.f, yWin))->SetScale(sf::Vector2f(xWin / 50.f, 1.f));
    mainScene.AddGameObject<feg::GameObject>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetPosition(sf::Vector2f(-50.f, 0.f))->SetScale(sf::Vector2f(1.f, yWin / 50.f));
    mainScene.AddGameObject<feg::GameObject>(tm.GetTexture("res/WhiteSquare.png")).get()
        ->SetPosition(sf::Vector2f(xWin, 0.f))->SetScale(sf::Vector2f(1.f, yWin / 50.f));
    mainScene.AddGameObject<feg::Player>(tm.GetTexture("res/WhiteSquare.png"), feg::Player::PlayerInput(
        sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z)).get()
        ->SetPosition(sf::Vector2f(100.f, yWin - 650.f))->SetColor(sf::Color(255, 0.f, 0.f))->SetScale(sf::Vector2f(1.f, 2.f));
    sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Fight Epitech Grades");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                mainScene.PressKey(event.key.code);
            else if (event.type == sf::Event::KeyReleased)
                mainScene.ReleaseKey(event.key.code);
            else if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        mainScene.Update(window);
        window.display();
    }
    return (0);
}
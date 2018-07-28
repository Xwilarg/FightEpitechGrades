#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "Crate.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "Ai.hpp"

constexpr static unsigned int xWin = 1200, yWin = 600;
static feg::GameManager gm;

void AddWalls(feg::Scene &scene)
{
    scene.AddGameObject<feg::GameObject>(gm.tm.GetTexture("res/WhiteSquare.png"))
        ->SetPosition(sf::Vector2f(0.f, yWin))->SetScale(sf::Vector2f(xWin / 50.f, 1.f))->SetTag(feg::GameObject::WALL);
    scene.AddGameObject<feg::GameObject>(gm.tm.GetTexture("res/WhiteSquare.png"))
        ->SetPosition(sf::Vector2f(0.f, -50.f))->SetScale(sf::Vector2f(xWin / 50.f, 1.f))->SetTag(feg::GameObject::WALL);
    scene.AddGameObject<feg::GameObject>(gm.tm.GetTexture("res/WhiteSquare.png"))
        ->SetPosition(sf::Vector2f(-50.f, 0.f))->SetScale(sf::Vector2f(1.f, yWin / 50.f))->SetTag(feg::GameObject::WALL);
    scene.AddGameObject<feg::GameObject>(gm.tm.GetTexture("res/WhiteSquare.png"))
        ->SetPosition(sf::Vector2f(xWin, 0.f))->SetScale(sf::Vector2f(1.f, yWin / 50.f))->SetTag(feg::GameObject::WALL);
}

int main()
{
    gm.pm.AddLayer(feg::PhysicsManager::PhysicsLayer::PLAYER, feg::PhysicsManager::PhysicsLayer::PLAYER);
    feg::Scene mainScene(gm);
    AddWalls(mainScene);
    mainScene.AddGameObject<feg::Crate>(gm.tm.GetTexture("res/WhiteSquare.png"))
        ->SetColor(sf::Color(139, 69, 19))->SetPosition(sf::Vector2f(350.f, 0.f));
    dynamic_cast<feg::Ai*>(mainScene.AddGameObject<feg::Ai>(gm.tm.GetTexture("res/WhiteSquare.png"), gm.tm)
        ->SetPosition(sf::Vector2f(xWin - 100.f, yWin - 350.f))->SetColor(sf::Color(0.f, 0.f, 255.f))->SetScale(sf::Vector2f(.5f, 1.f))->SetTag(feg::GameObject::PLAYER))
        ->SetTarget(
    mainScene.AddGameObject<feg::Player>(gm.tm.GetTexture("res/WhiteSquare.png"), gm.tm, feg::Player::PlayerInput(
        sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z, sf::Keyboard::Space))
        ->SetPosition(sf::Vector2f(100.f, yWin - 350.f))->SetColor(sf::Color(255.f, 0.f, 0.f))->SetScale(sf::Vector2f(.5f, 1.f))->SetTag(feg::GameObject::PLAYER)
        );
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
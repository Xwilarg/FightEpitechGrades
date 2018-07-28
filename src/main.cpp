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

void AddCrates(feg::Scene &scene, sf::Vector2f &&pos, int amount)
{
    for (int i = 0; i < amount; i++)
        scene.AddGameObject<feg::Crate>(gm.tm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color(139, 69, 19))->SetPosition(sf::Vector2f(pos.x, pos.y + 75.f * i));
}

int main()
{
    gm.pm.AddLayer(feg::PhysicsManager::PhysicsLayer::PLAYER, feg::PhysicsManager::PhysicsLayer::PLAYER);
    gm.pm.AddLayer(feg::PhysicsManager::PhysicsLayer::BULLET, feg::PhysicsManager::PhysicsLayer::BULLET);
    feg::Scene mainScene(gm);
    feg::Scene &currentScene = mainScene;
    AddWalls(mainScene);
    AddCrates(mainScene, sf::Vector2f(300.f, 50.f), 5);
    AddCrates(mainScene, sf::Vector2f(351.f, 50.f), 7);
    AddCrates(mainScene, sf::Vector2f(402.f, 50.f), 3);
    feg::GameObject* player = mainScene.AddGameObject<feg::Player>(gm.tm.GetTexture("res/WhiteSquare.png"), gm.tm, mainScene, feg::Player::PlayerInput(
        sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z, sf::Keyboard::K, sf::Keyboard::L))
        ->SetPosition(sf::Vector2f(100.f, yWin - 350.f))->SetColor(sf::Color(255.f, 0.f, 0.f))->SetScale(sf::Vector2f(.5f, 1.f))->SetTag(feg::GameObject::PLAYER);
    static_cast<feg::Ai*>(mainScene.AddGameObject<feg::Ai>(gm.tm.GetTexture("res/WhiteSquare.png"), gm.tm, mainScene)
        ->SetPosition(sf::Vector2f(xWin - 100.f, yWin - 350.f))->SetColor(sf::Color(0.f, 0.f, 255.f))->SetScale(sf::Vector2f(.5f, 1.f))->SetTag(feg::GameObject::PLAYER))
        ->SetTarget(player);
    sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Fight Epitech Grades");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                currentScene.PressKey(event.key.code);
            else if (event.type == sf::Event::KeyReleased)
                currentScene.ReleaseKey(event.key.code);
            else if (event.type == sf::Event::Closed)
                window.close();
        }
        currentScene.UpdateMousePosition(sf::Mouse::getPosition());

        window.clear(sf::Color::White);
        currentScene.Update(window);
        window.display();
    }
    return (0);
}
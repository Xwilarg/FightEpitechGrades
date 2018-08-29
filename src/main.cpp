#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "Crate.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "Ai.hpp"
#include "Switch.hpp"
#include "Text.hpp"
#include "Button.hpp"
#include "Handgun.hpp"
#include "Machinegun.hpp"
#include "MineLauncher.hpp"
#include "FileLister.hpp"

void LoadGames(feg::Scene **currentScene, feg::Scene &toAssign) noexcept
{
    *currentScene = &toAssign;
}

void UpdateFileLister(feg::FileLister &fl, feg::Text *text)
{
    const std::string *str = fl.GetCurrent();
    if (str == nullptr)
        text->SetString("None");
    else
        text->SetString(*str);
}

void LoadNextFileLister(feg::FileLister &fl, feg::Text *text)
{
    fl.Next();
    UpdateFileLister(fl, text);
}

void LoadPreviousFileLister(feg::FileLister &fl, feg::Text *text)
{
    fl.Previous();
    UpdateFileLister(fl, text);
}

int main()
{
    constexpr unsigned int xWin = 1600, yWin = 900;
    feg::GameManager gm;

    // PHYSIC LAYERS
    gm.pm.AddLayer(feg::PhysicsManager::PhysicsLayer::PLAYER, feg::PhysicsManager::PhysicsLayer::PLAYER);
    gm.pm.AddLayer(feg::PhysicsManager::PhysicsLayer::BULLET, feg::PhysicsManager::PhysicsLayer::BULLET);
    
    // SCENE CREATION
    feg::Scene mainScene(gm, "res/001.map", sf::Vector2f(xWin, yWin));
    feg::Scene mainMenu(gm, "res/menu.map", sf::Vector2f(xWin, yWin));
    feg::Scene *currentScene = &mainMenu;
    std::shared_ptr<feg::Player> player = std::make_shared<feg::Player>(gm.rm.GetTexture("res/Hana-left.png"), gm.rm.GetTexture("res/Hana-right.png"), gm.rm, mainScene, feg::Player::PlayerInput(
        sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z, sf::Keyboard::S, sf::Keyboard::K, sf::Keyboard::L),
        std::make_unique<feg::Handgun>(gm.rm), std::make_unique<feg::MineLauncher>(gm.rm));
    mainScene.AddObject(player)->SetPosition(sf::Vector2f(100.f, yWin - 350.f));
    mainMenu.AddObject(player)->SetPosition(sf::Vector2f(100.f, yWin - 350.f));
    static_cast<feg::Ai*>(mainScene.AddObject<feg::Ai>(gm.rm.GetTexture("res/Epichan-left.png"), gm.rm.GetTexture("res/Epichan-right.png"), gm.rm, mainScene,
        std::make_unique<feg::Handgun>(gm.rm), std::make_unique<feg::Machinegun>(gm.rm))
        ->SetPosition(sf::Vector2f(xWin - 100.f, yWin - 350.f)))
        ->SetTarget(player.get());

    // MENU CREATION
    mainMenu.AddObject<feg::Button>(gm.rm.GetTexture("res/WhiteSquare.png"))->SetFunction(std::bind(LoadGames, &currentScene, mainScene))->SetPosition(sf::Vector2f(1000.f, 525.f));
    mainMenu.AddObject(gm.rm.GetFont("res/arial.ttf"))->SetPosition(sf::Vector2f(1055.f, 530.f))->SetString("Play")->SetColor(sf::Color::Black);
    feg::FileLister files;
    feg::Text *fileText = mainMenu.AddObject(gm.rm.GetFont("res/arial.ttf"))->SetPosition(sf::Vector2f(1000.f, 300.f))->SetColor(sf::Color::Black)->SetSize(15);
    UpdateFileLister(files, fileText);
    mainMenu.AddObject<feg::Button>(gm.rm.GetTexture("res/WhiteSquare.png"))->SetFunction(std::bind(LoadPreviousFileLister, files, fileText))->SetPosition(sf::Vector2f(1000.f, 325.f));
    mainMenu.AddObject(gm.rm.GetFont("res/arial.ttf"))->SetPosition(sf::Vector2f(1015.f, 330.f))->SetString("<")->SetColor(sf::Color::Black);
    mainMenu.AddObject<feg::Button>(gm.rm.GetTexture("res/WhiteSquare.png"))->SetFunction(std::bind(LoadNextFileLister, files, fileText))->SetPosition(sf::Vector2f(1055.f, 325.f));
    mainMenu.AddObject(gm.rm.GetFont("res/arial.ttf"))->SetPosition(sf::Vector2f(1070.f, 330.f))->SetString(">")->SetColor(sf::Color::Black);

    // GAME
    sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Fight Epitech Grades");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        currentScene->SetMousePressed(false);
        currentScene->SetMouseReleased(false);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else
                    currentScene->PressKey(event.key.code);
            }
            else if (event.type == sf::Event::KeyReleased)
                currentScene->ReleaseKey(event.key.code);
            else if (event.type == sf::Event::MouseMoved)
                currentScene->UpdateMousePosition(sf::Mouse::getPosition());
            else if (event.type == sf::Event::MouseButtonPressed)
                currentScene->SetMousePressed(true);
            else if (event.type == sf::Event::MouseButtonReleased)
                currentScene->SetMouseReleased(true);
            else if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        currentScene->Update(window);
        window.display();
    }
    return (0);
}
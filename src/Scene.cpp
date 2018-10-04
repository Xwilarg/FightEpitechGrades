#include <fstream>
#include "Scene.hpp"
#include "Text.hpp"
#include "Crate.hpp"
#include "Ai.hpp"

namespace feg
{
    Scene::Scene(GameManager &manager, const sf::Vector2f &win) noexcept
        :  _manager(manager), _allGameObjects(), _gameObjectsToAdd(), _gameObjectsToRemove(),
        _keyPressed(), _mousePos(sf::Vector2i(0, 0)), _isMousePressed(false), _isMouseReleased(false),
        _marks(nullptr)
    {
        AddWalls(win);
    }

    void Scene::Update(sf::RenderWindow &window) noexcept
    {
        for (auto &go : _gameObjectsToAdd)
            _allGameObjects.push_back(std::move(go));
        _gameObjectsToAdd.clear();
        for (auto &go : _gameObjectsToRemove)
            _allGameObjects.erase(std::remove(_allGameObjects.begin(), _allGameObjects.end(), go), _allGameObjects.end());
        _gameObjectsToRemove.clear();
        for (auto &go : _allGameObjects)
            go->Update(*this, window);
        for (auto &txt : _allText)
            window.draw(txt->GetText());
    }

    Text *Scene::AddObject(const sf::Font &font) noexcept
    {
        _allText.push_back(std::make_shared<Text>(font));
        return (_allText.back().get());
    }

    void Scene::RemoveObject(Drawable *obj) noexcept
    {
        for (const auto& o : _allGameObjects)
        {
            if (o.get() == obj)
            {
                _gameObjectsToRemove.push_back(o);
                break;
            }
        }
    }

    void Scene::PressKey(sf::Keyboard::Key key) noexcept
    {
        if (std::find(_keyPressed.begin(), _keyPressed.end(), key) == _keyPressed.end())
            _keyPressed.push_back(key);
    }

    void Scene::ReleaseKey(sf::Keyboard::Key key) noexcept
    {
        if (std::find(_keyPressed.begin(), _keyPressed.end(), key) != _keyPressed.end())
            _keyPressed.erase(std::find(_keyPressed.begin(), _keyPressed.end(), key));
    }

    bool Scene::IsPressed(sf::Keyboard::Key key) const noexcept
    {
        return (std::find(_keyPressed.begin(), _keyPressed.end(), key) != _keyPressed.end());
    }

    bool Scene::DoesLayersCollide(PhysicsManager::PhysicsLayer layer1, PhysicsManager::PhysicsLayer layer2) const noexcept
    {
        return (_manager.pm.DoesLayersCollide(layer1, layer2));
    }

    void Scene::UpdateMousePosition(const sf::Vector2i &newPos) noexcept
    {
        _mousePos = newPos;
    }

    const sf::Vector2i &Scene::GetMousePosition() const noexcept
    {
        return (_mousePos);
    }

    void Scene::SetMousePressed(bool state) noexcept
    {
        _isMousePressed = state;
    }

    bool Scene::GetMousePressed() const noexcept
    {
        return (_isMousePressed);
    }

    void Scene::SetMouseReleased(bool state) noexcept
    {
        _isMouseReleased = state;
    }

    bool Scene::GetMouseReleased() const noexcept
    {
        return (_isMouseReleased);
    }

    void Scene::LoadFromFile(const std::string &mapFile)
    {
        std::ifstream file(mapFile, std::ios::in);
        if (!file)
            throw std::invalid_argument("Can't open " + mapFile);
        std::string line;
        int y = 0;
        constexpr float offset = 50.f;
        std::vector<PortalExit*> exits;
        while (getline(file, line))
        {
            for (unsigned int i = 0; i < line.size(); i++)
            {
                switch (line[i])
                {
                case 'o':
                    AddCrate(sf::Vector2f(i, y) * offset);
                    break;

                case 'x':
                    AddPlateform(sf::Vector2f(i, y) * offset);
                    break;

                case '^':
                {
                    PortalEntrance *entrance = AddPortalEntrance(sf::Vector2f(i, y) * offset);
                    if (exits.size() > 0)
                    {
                        entrance->SetExit(exits[0]);
                        exits.erase(exits.begin());
                    }
                    break;
                }

                case 'v':
                    exits.push_back(AddPortalExit(sf::Vector2f(i, y) * offset));
                    break;
                }
            }
            y++;
        }
    }

    void Scene::LoadGrades(const MarkFile &marks, const std::shared_ptr<feg::Player> &target) noexcept
    {
        _marks = &marks;
        SpawnAi(target);
    }

    void Scene::SpawnAi(const std::shared_ptr<feg::Player> &target) noexcept
    {
        static_cast<feg::Ai*>(AddObject<feg::Ai>(_manager.rm.GetTexture("res/Epichan-left.png"), _manager.rm.GetTexture("res/Epichan-right.png"), _manager.rm, *this,
        std::make_unique<feg::Handgun>(_manager.rm), std::make_unique<feg::Machinegun>(_manager.rm))
        ->SetPosition(sf::Vector2f(_manager._xWin - 100.f, _manager._yWin - 350.f)))
        ->SetTarget(&target);
    }

    void Scene::Clear() noexcept
    {
        _allGameObjects.clear();
        _gameObjectsToAdd.clear();
        _gameObjectsToRemove.clear();
        _allText.clear();
    }

    void Scene::AddWalls(const sf::Vector2f &win) noexcept
    {
        AddObject<GameObject>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, win.y))->SetScale(sf::Vector2f(win.x / 50.f + 50.f, 1.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, -50.f))->SetScale(sf::Vector2f(win.x / 50.f + 50.f, 1.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, 0.f))->SetScale(sf::Vector2f(1.f, win.y / 50.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(win.x, 0.f))->SetScale(sf::Vector2f(1.f, win.y / 50.f))->SetTag(feg::GameObject::WALL);
    }

    void Scene::AddCrate(sf::Vector2f &&pos) noexcept
    {
        AddObject<Crate>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color(139, 69, 19))->SetPosition(sf::Vector2f(pos.x, pos.y));
    }

    void Scene::AddPlateform(sf::Vector2f &&pos) noexcept
    {
        AddObject<GameObject>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color::Black)->SetPosition(sf::Vector2f(pos.x, pos.y));
    }

    PortalEntrance *Scene::AddPortalEntrance(sf::Vector2f &&pos) noexcept
    {
        return (static_cast<PortalEntrance*>(AddObject<PortalEntrance>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color(0, 0, 255, 127))->SetPosition(sf::Vector2f(pos.x, pos.y))));
    }

    PortalExit *Scene::AddPortalExit(sf::Vector2f &&pos) noexcept
    {
        return (static_cast<PortalExit*>(AddObject<PortalExit>(_manager.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color(255, 165, 0, 127))->SetPosition(sf::Vector2f(pos.x, pos.y))));
    }
}
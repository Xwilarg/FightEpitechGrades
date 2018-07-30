#include <fstream>
#include "Scene.hpp"
#include "Text.hpp"
#include "Crate.hpp"

namespace feg
{
    Scene::Scene(GameManager &manager, std::string &&mapFile, const sf::Vector2f &win) noexcept
        :  _manager(manager), _allGameObjects(), _gameObjectsToAdd(), _gameObjectsToRemove(),
        _keyPressed(), _mousePos(sf::Vector2i(0, 0)), _isMousePressed(false), _isMouseReleased(false)
    {
        AddWalls(manager, win);
        std::ifstream file(mapFile, std::ios::in);
        if (!file)
            throw std::invalid_argument("Can't open " + mapFile);
        std::string line;
        int y = 0;
        constexpr float offset = 50.f;
        while (getline(file, line))
        {
            for (unsigned int i = 0; i < line.size(); i++)
            {
                switch (line[i])
                {
                case 'o':
                    AddCrate(sf::Vector2f(i, y) * offset, manager);
                    break;

                case 'x':
                    AddPlateform(sf::Vector2f(i, y) * offset, manager);
                    break;
                }
            }
            y++;
        }
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

    void Scene::AddWalls(GameManager &gm, const sf::Vector2f &win) noexcept
    {
        AddObject<GameObject>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, win.y))->SetScale(sf::Vector2f(win.x / 50.f + 50.f, 1.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, -50.f))->SetScale(sf::Vector2f(win.x / 50.f + 50.f, 1.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(-50.f, 0.f))->SetScale(sf::Vector2f(1.f, win.y / 50.f))->SetTag(feg::GameObject::WALL);
        AddObject<GameObject>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetPosition(sf::Vector2f(win.x, 0.f))->SetScale(sf::Vector2f(1.f, win.y / 50.f))->SetTag(feg::GameObject::WALL);
    }

    void Scene::AddCrate(sf::Vector2f &&pos, GameManager &gm) noexcept
    {
        AddObject<Crate>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color(139, 69, 19))->SetPosition(sf::Vector2f(pos.x, pos.y));
    }

    void Scene::AddPlateform(sf::Vector2f &&pos, GameManager &gm) noexcept
    {
        AddObject<GameObject>(gm.rm.GetTexture("res/WhiteSquare.png"))
            ->SetColor(sf::Color::Black)->SetPosition(sf::Vector2f(pos.x, pos.y + 75.f));
    }
}
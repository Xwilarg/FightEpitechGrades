#include "Scene.hpp"

namespace feg
{
    Scene::Scene(const GameManager &manager) noexcept
        : _manager(manager), _allGameObjects(), _toAdd(), _toRemove(),
        _keyPressed(), _mousePos(sf::Vector2i(0, 0)), _isMousePressed(false), _isMouseReleased(false)
    { }

    void Scene::Update(sf::RenderWindow &window) noexcept
    {
        for (auto &go : _toAdd)
            _allGameObjects.push_back(std::move(go));
        _toAdd.clear();
        for (auto &go : _toRemove)
            _allGameObjects.erase(std::remove(_allGameObjects.begin(), _allGameObjects.end(), go), _allGameObjects.end());
        _toRemove.clear();
        for (auto &go : _allGameObjects)
            go->Update(*this, window);
    }

    void Scene::RemoveGameObject(GameObject *obj) noexcept
    {
        for (const auto& o : _allGameObjects)
        {
            if (o.get() == obj)
            {
                _toRemove.push_back(o);
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
}
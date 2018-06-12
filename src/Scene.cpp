#include "Scene.hpp"

namespace feg
{
    Scene::Scene(const PhysicsManager &physics) noexcept
        : _physics(physics), _allGameObjects(), _keyPressed()
    { }

    void Scene::Update(sf::RenderWindow &window) noexcept
    {
        for (auto &go : _allGameObjects)
        {
            go.get()->Update(*this, window);
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
        return (_physics.DoesLayersCollide(layer1, layer2));
    }
}
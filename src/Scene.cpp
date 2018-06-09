#include "Scene.hpp"

namespace feg
{
    Scene::Scene() noexcept
        : _allGameObjects()
    { }

    void Scene::Update(sf::RenderWindow &window) noexcept
    {
        for (auto &go : _allGameObjects)
        {
            go.get()->Update(window);
        }
    }
}
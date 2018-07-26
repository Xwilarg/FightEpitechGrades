#ifndef SCENE_HPP_
# define SCENE_HPP_

# include <memory>
# include "GameObject.hpp"
# include "GameManager.hpp"
#include <iostream>
namespace feg
{
    class Scene final
    {
    public:
        Scene(const GameManager &manager) noexcept;
        ~Scene() noexcept = default;
        void Update(sf::RenderWindow &window) noexcept;
        const std::vector<std::shared_ptr<GameObject> > &GetAllGameObjects() const noexcept
        { return (_allGameObjects); }

        template<typename T, typename... Args>
        GameObject *AddGameObject(Args &&... args)
        {
            _allGameObjects.push_back(std::make_shared<T>(std::forward<Args>(args)...));
            return (_allGameObjects.back().get());
        }

        void PressKey(sf::Keyboard::Key key) noexcept;
        void ReleaseKey(sf::Keyboard::Key key) noexcept;
        bool IsPressed(sf::Keyboard::Key key) const noexcept;

        bool DoesLayersCollide(PhysicsManager::PhysicsLayer layer1, PhysicsManager::PhysicsLayer layer2) const noexcept;

    private:
        const GameManager &_manager;
        std::vector<std::shared_ptr<GameObject> > _allGameObjects;
        std::vector<sf::Keyboard::Key> _keyPressed;
    };
}

#endif // !SCENE
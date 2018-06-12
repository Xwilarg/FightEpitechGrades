#ifndef SCENE_HPP_
# define SCENE_HPP_

# include <memory>
# include "GameObject.hpp"

namespace feg
{
    class Scene final
    {
    public:
        Scene(const PhysicsManager &physics) noexcept;
        ~Scene() noexcept = default;
        void Update(sf::RenderWindow &window) noexcept;
        const std::vector<std::shared_ptr<GameObject> > &GetAllGameObjects() const noexcept
        { return (_allGameObjects); }

        template<typename T, typename... Args>
        GameObject *AddGameObject(Args &&... args)
        {
            _allGameObjects.push_back(std::make_shared<T>(args...));
            return (_allGameObjects[_allGameObjects.size() - 1].get());
        }

        void PressKey(sf::Keyboard::Key key) noexcept;
        void ReleaseKey(sf::Keyboard::Key key) noexcept;
        bool IsPressed(sf::Keyboard::Key key) const noexcept;

        bool DoesLayersCollide(PhysicsManager::PhysicsLayer layer1, PhysicsManager::PhysicsLayer layer2) const noexcept;

    private:
        const PhysicsManager &_physics;
        std::vector<std::shared_ptr<GameObject> > _allGameObjects;
        std::vector<sf::Keyboard::Key> _keyPressed;
    };
}

#endif // !SCENE
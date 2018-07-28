#ifndef SCENE_HPP_
# define SCENE_HPP_

# include <memory>
# include "GameObject.hpp"
# include "GameManager.hpp"

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
        GameObject *AddGameObject(Args &&... args) noexcept
        {
            _toAdd.push_back(std::make_shared<T>(std::forward<Args>(args)...));
            return (_toAdd.back().get());
        }

        template<typename T>
        GameObject *AddGameObject(std::unique_ptr<T> &&obj) noexcept
        {
            _toAdd.push_back(std::move(obj));
            return (_toAdd.back().get());
        }

        template<typename T>
        GameObject *AddGameObject(const std::shared_ptr<T> &obj) noexcept
        {
            _toAdd.push_back(std::move(obj));
            return (_toAdd.back().get());
        }

        void RemoveGameObject(GameObject *obj) noexcept;

        void PressKey(sf::Keyboard::Key key) noexcept;
        void ReleaseKey(sf::Keyboard::Key key) noexcept;
        bool IsPressed(sf::Keyboard::Key key) const noexcept;
        bool DoesLayersCollide(PhysicsManager::PhysicsLayer layer1, PhysicsManager::PhysicsLayer layer2) const noexcept;
        void UpdateMousePosition(const sf::Vector2i &newPos) noexcept;
        const sf::Vector2i &GetMousePosition() const noexcept;
        void SetMousePressed(bool state) noexcept;
        bool GetMousePressed() const noexcept;
        void SetMouseReleased(bool state) noexcept;
        bool GetMouseReleased() const noexcept;

    private:
        const GameManager &_manager;
        std::vector<std::shared_ptr<GameObject> > _allGameObjects;
        std::vector<std::shared_ptr<GameObject> > _toAdd;
        std::vector<std::shared_ptr<GameObject> > _toRemove;
        std::vector<sf::Keyboard::Key> _keyPressed;
        sf::Vector2i _mousePos;
        bool _isMousePressed;
        bool _isMouseReleased;
    };
}

#endif // !SCENE_HPP
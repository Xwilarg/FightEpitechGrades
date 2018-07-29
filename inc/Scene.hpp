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
        const std::vector<std::shared_ptr<Drawable> > &GetAllObjects() const noexcept
        { return (_allObjects); }

        template<typename T, typename... Args>
        T *AddObject(Args &&... args) noexcept
        {
            _toAdd.push_back(std::make_shared<T>(std::forward<Args>(args)...));
            return (static_cast<T*>(_toAdd.back().get()));
        }

        template<typename T>
        T *AddObject(std::unique_ptr<T> &&obj) noexcept
        {
            _toAdd.push_back(std::move(obj));
            return (static_cast<T*>(_toAdd.back().get()));
        }

        template<typename T>
        T *AddObject(const std::shared_ptr<T> &obj) noexcept
        {
            _toAdd.push_back(std::move(obj));
            return (static_cast<T*>(_toAdd.back().get()));
        }

        void RemoveObject(Drawable *obj) noexcept;

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
        std::vector<std::shared_ptr<Drawable> > _allObjects;
        std::vector<std::shared_ptr<Drawable> > _toAdd;
        std::vector<std::shared_ptr<Drawable> > _toRemove;
        std::vector<sf::Keyboard::Key> _keyPressed;
        sf::Vector2i _mousePos;
        bool _isMousePressed;
        bool _isMouseReleased;
    };
}

#endif // !SCENE_HPP
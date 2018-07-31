#ifndef SCENE_HPP_
# define SCENE_HPP_

# include <memory>
# include "GameObject.hpp"
# include "GameManager.hpp"

namespace feg
{
    class Text;

    class Scene final
    {
    public:
        Scene(GameManager &manager, std::string &&mapFile, const sf::Vector2f &win) noexcept;
        ~Scene() noexcept = default;
        void Update(sf::RenderWindow &window) noexcept;
        const std::vector<std::shared_ptr<GameObject> > &GetAllGameObjects() const noexcept
        { return (_allGameObjects); }

        Text *AddObject(const sf::Font &font) noexcept;

        template<typename T, typename... Args>
        T *AddObject(Args &&... args) noexcept
        {
            _gameObjectsToAdd.push_back(std::make_shared<T>(std::forward<Args>(args)...));
            return (static_cast<T*>(_gameObjectsToAdd.back().get()));
        }

        template<typename T>
        T *AddObject(std::unique_ptr<T> &&obj) noexcept
        {
            _gameObjectsToAdd.push_back(std::move(obj));
            return (static_cast<T*>(_gameObjectsToAdd.back().get()));
        }

        template<typename T>
        T *AddObject(const std::shared_ptr<T> &obj) noexcept
        {
            _gameObjectsToAdd.push_back(std::move(obj));
            return (static_cast<T*>(_gameObjectsToAdd.back().get()));
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
        void AddWalls(GameManager &gm, const sf::Vector2f &win) noexcept;
        void AddCrate(sf::Vector2f &&pos, GameManager &gm) noexcept;
        void AddPlateform(sf::Vector2f &&pos, GameManager &gm) noexcept;
        void AddPortalEntrance(sf::Vector2f &&pos, GameManager &gm) noexcept;
        void AddPortalExit(sf::Vector2f &&pos, GameManager &gm) noexcept;
        const GameManager &_manager;
        std::vector<std::shared_ptr<GameObject> > _allGameObjects;
        std::vector<std::shared_ptr<GameObject> > _gameObjectsToAdd;
        std::vector<std::shared_ptr<GameObject> > _gameObjectsToRemove;
        std::vector<std::shared_ptr<Text> > _allText;
        std::vector<sf::Keyboard::Key> _keyPressed;
        sf::Vector2i _mousePos;
        bool _isMousePressed;
        bool _isMouseReleased;
    };
}

#endif // !SCENE_HPP
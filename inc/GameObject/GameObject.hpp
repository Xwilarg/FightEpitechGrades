#ifndef GAMEOBJECT_HPP_
# define GAMEOBJECT_HPP_

# include <SFML/Graphics.hpp>
# include "PhysicsManager.hpp"

namespace feg
{
    class Scene;

    class GameObject
    {
    public:
        enum Tag
        {
            NONE,
            WALL,
            BULLET,
            PLAYER
        };
        GameObject(const sf::Texture &texture) noexcept;
        virtual ~GameObject() noexcept = default;
        virtual void Update(Scene &scene, sf::RenderWindow &window) noexcept;
        GameObject *SetColor(sf::Color &&color) noexcept;
        GameObject *SetColor(const sf::Color &color) noexcept;
        GameObject *SetScale(sf::Vector2f &&scale) noexcept;
        GameObject *SetPosition(sf::Vector2f &&size) noexcept;
        GameObject *SetPosition(const sf::Vector2f &size) noexcept;
        GameObject *SetLayer(PhysicsManager::PhysicsLayer layer) noexcept;
        GameObject *SetTag(Tag tag) noexcept;
        GameObject *SetParent(GameObject *go) noexcept;
        bool operator==(const GameObject &go) const noexcept;
        bool operator!=(const GameObject &go) const noexcept;

    protected:
        void Translate(const sf::Vector2f &pos) noexcept;

    private:
        sf::Sprite _sprite;
        sf::Vector2f _position;
        const sf::Vector2f _baseSize;
        sf::Vector2f _size;
        int _myId;
        PhysicsManager::PhysicsLayer _layer;
        static int id;
        Tag _tag;
        GameObject *_parent;

    public:
        const sf::Vector2f &GetPosition() const noexcept { return (_position); }
        const sf::Vector2f &GetSize() const noexcept { return (_size); }
        PhysicsManager::PhysicsLayer GetLayer() const noexcept { return (_layer); }
        Tag GetTag() const noexcept { return (_tag); }
    };
}

#endif // !GAMEOBJECT_HPP_
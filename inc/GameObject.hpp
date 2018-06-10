#ifndef GAMEOBJECT_HPP_
# define GAMEOBJECT_HPP_

# include <SFML/Graphics.hpp>

namespace feg
{
    class Scene;

    class GameObject
    {
    public:
        GameObject(const sf::Texture &texture) noexcept;
        virtual ~GameObject() noexcept = default;
        virtual void Update(const Scene &scene, sf::RenderWindow &window) noexcept;
        GameObject *SetColor(sf::Color &&color) noexcept;
        GameObject *SetSize(sf::Vector2f &&size) noexcept;
        GameObject *SetPosition(sf::Vector2f &&size) noexcept;
        bool operator==(const GameObject &go) const noexcept;
        bool operator!=(const GameObject &go) const noexcept;

    protected:
        void Translate(const sf::Vector2f &pos) noexcept;

    private:
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _size;
        int _myId;
        static int id;

    public:
        const sf::Vector2f &GetPosition() const noexcept { return (_position); }
        const sf::Vector2f &GetSize() const noexcept { return (_size); }
    };
}

#endif // !GAMEOBJECT_HPP_
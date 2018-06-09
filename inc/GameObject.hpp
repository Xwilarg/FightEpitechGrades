#ifndef GAMEOBJECT_HPP_
# define GAMEOBJECT_HPP_

# include <SFML/Graphics.hpp>

namespace feg
{
    class GameObject
    {
    public:
        virtual ~GameObject() noexcept = default;
        virtual void SetColor(sf::Color &&color) noexcept;
        virtual void Update(sf::RenderWindow &window) noexcept;

    protected:
        GameObject(const sf::Texture &texture) noexcept;

    private:
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _size;

    public:
        const sf::Vector2f &GetPosition() const noexcept { return (_position); }
        const sf::Vector2f &GetSize() const noexcept { return (_size); }
    };
}

#endif // !GAMEOBJECT_HPP_
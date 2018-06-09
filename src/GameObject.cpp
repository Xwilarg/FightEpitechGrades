#include "GameObject.hpp"

namespace feg
{
    GameObject::GameObject(const sf::Texture &texture) noexcept
        : _sprite(texture), _position(sf::Vector2f(0.f, 0.f)), _size(sf::Vector2f(1.f, 1.f))
    { }

    void GameObject::Update(sf::RenderWindow &window) noexcept
    {
        window.draw(_sprite);
    }

    void GameObject::SetColor(sf::Color &&color) noexcept
    {
        _sprite.setColor(std::move(color));
    }

    void GameObject::Translate(const sf::Vector2f &pos) noexcept
    {
        _position += pos;
        _sprite.setPosition(_position);
    }
}
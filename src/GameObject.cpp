#include "GameObject.hpp"

namespace feg
{
    GameObject::GameObject(const sf::Texture &texture) noexcept
        : _sprite(texture), _position(sf::Vector2f(0.f, 0.f)), _size(sf::Vector2f(50.f, 50.f)),
        _myId(id++)
    { }

    void GameObject::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        window.draw(_sprite);
    }

    GameObject *GameObject::SetColor(sf::Color &&color) noexcept
    {
        _sprite.setColor(std::move(color));
        return (this);
    }

    GameObject *GameObject::SetSize(sf::Vector2f &&size) noexcept
    {
        _size = std::move(size);
        return (this);
    }

    GameObject *GameObject::SetPosition(sf::Vector2f &&pos) noexcept
    {
        _position = std::move(pos);
        _sprite.setPosition(_position);
        return (this);
    }

    bool GameObject::operator==(const GameObject &go) const noexcept
    {
        return (_myId == go._myId);
    }

    bool GameObject::operator!=(const GameObject &go) const noexcept
    {
        return (_myId != go._myId);
    }

    void GameObject::Translate(const sf::Vector2f &pos) noexcept
    {
        _position += pos;
        _sprite.setPosition(_position);
    }

    int GameObject::id = 0;
}
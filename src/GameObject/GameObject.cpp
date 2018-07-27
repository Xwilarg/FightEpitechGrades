#include "GameObject.hpp"

namespace feg
{
    GameObject::GameObject(const sf::Texture &texture) noexcept
        : _sprite(texture), _position(sf::Vector2f(0.f, 0.f)),
        _baseSize(sf::Vector2f(50.f, 50.f)), _size(_baseSize),
        _myId(id++), _layer(PhysicsManager::PhysicsLayer::NONE),
        _tag(NONE)
    { }

    void GameObject::Update(Scene &, sf::RenderWindow &window) noexcept
    {
        window.draw(_sprite);
    }

    GameObject *GameObject::SetColor(sf::Color &&color) noexcept
    {
        _sprite.setColor(std::move(color));
        return (this);
    }

    GameObject *GameObject::SetScale(sf::Vector2f &&scale) noexcept
    {
        _sprite.setScale(scale);
        _size = sf::Vector2f(_baseSize.x * scale.x, _baseSize.y * scale.y);
        return (this);
    }

    GameObject *GameObject::SetPosition(sf::Vector2f &&pos) noexcept
    {
        _position = std::move(pos);
        _sprite.setPosition(_position);
        return (this);
    }

    GameObject *GameObject::SetPosition(const sf::Vector2f &pos) noexcept
    {
        _position = pos;
        _sprite.setPosition(_position);
        return (this);
    }

    GameObject *GameObject::SetLayer(PhysicsManager::PhysicsLayer layer) noexcept
    {
        _layer = layer;
        return (this);
    }

    GameObject *GameObject::SetTag(Tag tag) noexcept
    {
        _tag = tag;
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
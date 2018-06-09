#include "MovableGameObject.hpp"

namespace feg
{
    MovableGameObject::MovableGameObject(const sf::Texture &texture) noexcept
        : GameObject(texture), _linearVelocity(sf::Vector2f(0.f, 0.f)), _linearDrag(1.1f),
        _gravity(.6f)
    { }

    void MovableGameObject::Update(sf::RenderWindow &window) noexcept
    {
        GameObject::Update(window);
        AddForce(sf::Vector2f(0.f, _gravity));
        Translate(_linearVelocity);
        _linearVelocity /= _linearDrag;
    }

    void MovableGameObject::AddForce(const sf::Vector2f &force)
    {
        _linearVelocity += force;
    }

    bool MovableGameObject::DoesCollide(const GameObject &go)
    {
        return (DoesAxisCollide(GetPosition().x, GetSize().x, go.GetPosition().x, go.GetSize().x)
                && DoesAxisCollide(GetPosition().y, GetSize().y, go.GetPosition().y, go.GetSize().y));
    }

    bool MovableGameObject::DoesAxisCollide(const float myPosition, const float mySize, const float otherPosition, const float otherSize) const noexcept
    {
        return ((myPosition - mySize / 2 < otherPosition - otherSize / 2
                && myPosition + mySize / 2 > otherPosition - otherSize / 2)
                || (myPosition - mySize / 2 < otherPosition + otherSize / 2
                && myPosition + mySize / 2 > otherPosition + otherSize / 2));
    }
}
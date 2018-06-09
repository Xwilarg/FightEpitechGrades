#include "MovableGameObject.hpp"

namespace feg
{
    MovableGameObject::MovableGameObject(const sf::Texture &texture) noexcept
        : GameObject(texture), _linearVelocity(sf::Vector2f(0.f, 0.f)), _linearDrag(0.1f)
    { }

    void MovableGameObject::Update(sf::RenderWindow &window) noexcept
    {
        GameObject::Update(window);
        _linearVelocity /= _linearDrag;
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
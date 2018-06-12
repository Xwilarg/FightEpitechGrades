#include "MovableGameObject.hpp"
#include "Scene.hpp"

namespace feg
{
    MovableGameObject::MovableGameObject(const sf::Texture &texture) noexcept
        : GameObject(texture), _linearVelocity(sf::Vector2f(0.f, 0.f)), _linearDrag(1.1f),
        _gravity(1.1f), _isOnFloor(false)
    { }

    void MovableGameObject::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        GameObject::Update(scene, window);
        AddForce(sf::Vector2f(0.f, _gravity));
        bool canMoveX = true;
        bool canMoveY = true;
        for (const auto &go : scene.GetAllGameObjects())
        {
            if (*go.get() != *this && !scene.DoesLayersCollide(GetLayer(), go.get()->GetLayer()))
            {
                if (DoesCollide(*go.get()))
                {
                    if (DoesCollide(*go.get(), true, false))
                        canMoveX = false;
                    if (DoesCollide(*go.get(), false, true))
                        canMoveY = false;
                    
                }
            }
        }
        if (canMoveX)
            Translate(sf::Vector2f(_linearVelocity.x, 0.f));
        else
            _linearVelocity = sf::Vector2f(0.f, _linearVelocity.y);
        if (canMoveY)
        {
            Translate(sf::Vector2f(0.f, _linearVelocity.y));
            _isOnFloor = false;
        }
        else
        {
            if (_linearVelocity.y > 0.f)
                _isOnFloor = true;
            _linearVelocity = sf::Vector2f(_linearVelocity.x, 0.f);
        }
        _linearVelocity /= _linearDrag;
    }

    void MovableGameObject::AddForce(const sf::Vector2f &force)
    {
        _linearVelocity += force;
    }

    bool MovableGameObject::DoesCollide(const GameObject &go, bool addXVelocity, bool addYVelocity)
    {
        return (DoesAxisCollide(GetPosition().x + ((addXVelocity) ? (_linearVelocity.x) : (0)), GetSize().x, go.GetPosition().x, go.GetSize().x)
        && DoesAxisCollide(GetPosition().y + ((addYVelocity) ? (_linearVelocity.y) : (0)), GetSize().y, go.GetPosition().y, go.GetSize().y));
    }

    bool MovableGameObject::DoesAxisCollide(const float myPosition, const float mySize, const float otherPosition, const float otherSize) const noexcept
    {
        return ((myPosition + mySize <= otherPosition + otherSize
                && myPosition + mySize >= otherPosition)
                || (myPosition <= otherPosition + otherSize
                && myPosition >= otherPosition)
                || (myPosition >= otherPosition
                && myPosition + mySize <= otherPosition + otherSize)
                || (myPosition <= otherPosition
                && myPosition + mySize >= otherPosition + otherSize));
    }
}
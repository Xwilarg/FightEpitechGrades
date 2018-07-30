#include "MovableGameObject.hpp"
#include "Scene.hpp"
#include "Character.hpp"

namespace feg
{
    MovableGameObject::MovableGameObject(const sf::Texture &texture) noexcept
        : GameObject(texture), _linearVelocity(sf::Vector2f(0.f, 0.f)), _linearDrag(1.1f),
        _gravity(1.1f), _hasGravity(true), _isOnFloor(false)
    { }

    void MovableGameObject::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        GameObject::Update(scene, window);
        if (_hasGravity)
            AddForce(sf::Vector2f(0.f, _gravity));
        bool canMoveX = true;
        bool canMoveY = true;
        bool collideLeftWall = false;
        bool collideRightWall = false;
        for (const auto &go : scene.GetAllGameObjects())
        {
            if (*go != *this && !scene.DoesLayersCollide(GetLayer(), go->GetLayer()))
            {
                if (DoesCollide(*go, true, true))
                {
                    bool collideX = DoesCollide(*go, true, false);
                    bool collideY = DoesCollide(*go, false, true);
                    if (GetTag() == PLAYER && go->GetTag() != BULLET && (collideX || (collideY && go->GetPosition().y > GetPosition().y)))
                        static_cast<Character*>(this)->SetCanDoubleJump(true);
                    if (GetTag() == GameObject::BULLET)
                    {
                        scene.RemoveObject(this);
                        if (go->GetTag() == GameObject::PLAYER)
                            static_cast<Character*>(go.get())->GetHit(scene, static_cast<Bullet*>(this));
                    }
                    else if (go->GetTag() == GameObject::BULLET)
                    {
                        scene.RemoveObject(go.get());
                        if (GetTag() == GameObject::PLAYER)
                        {
                            scene.RemoveObject(go.get());
                            static_cast<Character*>(this)->GetHit(scene, static_cast<Bullet*>(go.get()));
                        }
                        continue;
                    }
                    if (collideX)
                    {
                        canMoveX = false;
                        if (go->GetTag() != GameObject::BULLET)
                        {
                            if (_linearVelocity.x < -0.01f)
                                collideLeftWall = true;
                            else if (_linearVelocity.x > 0.01f)
                                collideRightWall = true;
                        }
                    }
                    if (collideY)
                    {
                        canMoveY = false;
                        if (go->GetPosition().y > GetPosition().y)
                            SetPosition(sf::Vector2f(GetPosition().x, go->GetPosition().y - go->GetSize().y - .01f));
                    }
                }
            }
        }
        if (GetTag() == PLAYER)
        {
            static_cast<Character*>(this)->SetOnLeftWall(collideLeftWall);
            static_cast<Character*>(this)->SetOnRightWall(collideRightWall);
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

    void MovableGameObject::AddForce(const sf::Vector2f &force) noexcept
    {
        _linearVelocity += force;
    }

    void MovableGameObject::InvertVelocity() noexcept
    {
        _linearVelocity = -_linearVelocity;
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
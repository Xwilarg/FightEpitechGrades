#include "Character.hpp"

namespace feg
{
    Character::Character(const sf::Texture &texture) noexcept
        : MovableGameObject(texture),
        _movForce(1.2f), _jumpForce(50.f)
    {
        SetLayer(PhysicsManager::PhysicsLayer::PLAYER);
    }

    void Character::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }

    void Character::GoLeft() noexcept
    {
        AddForce(sf::Vector2f(-_movForce, 0.f));
    }

    void Character::GoRight() noexcept
    {
        AddForce(sf::Vector2f(_movForce, 0.f));
    }

    void Character::Jump() noexcept
    {
        if (IsOnFloor())
            AddForce(sf::Vector2f(0.f, -_jumpForce));
    }
}
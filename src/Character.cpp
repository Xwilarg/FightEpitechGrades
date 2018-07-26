#include "Character.hpp"
#include "Scene.hpp"

namespace feg
{
    Character::Character(const sf::Texture &texture, TextureManager &tm) noexcept
        : MovableGameObject(texture), _weapon(tm),
        _movForce(1.2f), _jumpForce(50.f)
    {
        SetLayer(PhysicsManager::PhysicsLayer::PLAYER);
    }

    void Character::Update(Scene &scene, sf::RenderWindow &window) noexcept
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

    void Character::Fire(Scene &scene) const noexcept
    {
        scene.AddGameObject<Bullet>(_weapon.Fire())
            ->SetColor(sf::Color(0.f, 0.f, 0.f))
            ->SetPosition(GetPosition())
            ->SetLayer(PhysicsManager::NOCOLLISION);
    }
}
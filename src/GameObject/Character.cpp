#include "Character.hpp"
#include "Scene.hpp"

namespace feg
{
    Character::Character(const sf::Texture &texture, TextureManager &tm) noexcept
        : MovableGameObject(texture), _weapon(tm),
        _movForce(1.2f), _jumpForce(50.f), _isFacingRight(false),
        _health(100), _jumpChrono(200)
    {
        SetLayer(PhysicsManager::PhysicsLayer::PLAYER);
    }

    void Character::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }

    void Character::GoLeft() noexcept
    {
        _isFacingRight = false;
        AddForce(sf::Vector2f(-_movForce, 0.f));
    }

    void Character::GoRight() noexcept
    {
        _isFacingRight = true;
        AddForce(sf::Vector2f(_movForce, 0.f));
    }

    void Character::Jump() noexcept
    {
        if (IsOnLeftWall())
        {
            AddForce(sf::Vector2f(_jumpForce, 2.f * -_jumpForce / 3.f));
            _jumpChrono.Reset();
        }
        else if (IsOnRightWall())
        {
            AddForce(sf::Vector2f(-_jumpForce, 2.f * -_jumpForce / 3.f));
            _jumpChrono.Reset();
        }
        else if (IsOnFloor())
        {
            AddForce(sf::Vector2f(0.f, -_jumpForce));
            _jumpChrono.Reset();
        }
        else if (_canDoubleJump && _jumpChrono.IsEnded())
        {
            _canDoubleJump = false;
            AddForce(sf::Vector2f(0.f, -_jumpForce / 2.f));
        }
    }

    void Character::Fire(Scene &scene) noexcept
    {
        std::unique_ptr<Bullet> bullet = _weapon.Fire();
        if (bullet == nullptr)
            return;
        sf::Vector2f pos = GetPosition();
        bullet->SetPosition(sf::Vector2f(pos.x + ((_isFacingRight) ? (55.f) : (-55.f)), pos.y));
        if (!_isFacingRight)
            bullet->InvertVelocity();
        scene.AddGameObject<Bullet>(std::move(bullet));
    }
}
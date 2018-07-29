#include "Character.hpp"
#include "Scene.hpp"
#include "HealthBar.hpp"

namespace feg
{
    Character::Character(const sf::Texture &texture, ResourcesManager &tm, Scene &scene) noexcept
        : MovableGameObject(texture), _weapon1(tm), _weapon2(tm),
        _movForce(1.2f), _jumpForce(50.f), _isFacingRight(false),
        _health(100), _jumpChrono(200),
        _healthBar(static_cast<HealthBar*>(scene.AddObject(std::make_unique<HealthBar>(tm.GetTexture("res/WhiteSquare.png")))->SetParent(this)->SetColor(sf::Color::Green)))
    {
        SetLayer(PhysicsManager::PhysicsLayer::PLAYER);
    }

    void Character::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }

    void Character::GetHit(Scene &scene, Bullet *bullet) noexcept
    {
        _health -= bullet->GetDamage();
        if (_health > 0)
            _healthBar->SetScale(sf::Vector2f(_health / 100.f, .2f));
        else
        {
            scene.RemoveObject(_healthBar);
            scene.RemoveObject(this);
        }
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

    void Character::Fire1(Scene &scene) noexcept
    {
        FireInternal(scene, _weapon1);
    }

    void Character::Fire2(Scene &scene) noexcept
    {
        FireInternal(scene, _weapon2);
    }

    void Character::FireInternal(Scene &scene, Gun &gun) noexcept
    {
        std::unique_ptr<Bullet> bullet = gun.Fire();
        if (bullet == nullptr)
            return;
        sf::Vector2f pos = GetPosition();
        bullet->SetPosition(sf::Vector2f(pos.x + ((_isFacingRight) ? (55.f) : (-55.f)), pos.y));
        if (!_isFacingRight)
            bullet->InvertVelocity();
        scene.AddObject(std::move(bullet));
    }
}
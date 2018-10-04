#include "Character.hpp"
#include "Scene.hpp"
#include "HealthBar.hpp"

namespace feg
{
    Character::Character(const sf::Texture &textureLeft, const sf::Texture &textureRight, ResourcesManager &tm, Scene &scene,
                        std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept
        : MovableGameObject(textureLeft), _weapon1(std::move(weapon1)), _weapon2(std::move(weapon2)),
        _movForce(1.1f), _jumpForce(40.f), _isFacingRight(false),
        _health(100), _jumpChrono(200), _fallChrono(200),
        _healthBar(static_cast<HealthBar*>(scene.AddObject(std::make_unique<HealthBar>(tm.GetTexture("res/WhiteSquare.png")))->SetParent(this)->SetColor(sf::Color::Green))),
        _isOnLeftWall(false), _isOnRightWall(false), _canJump(false), _canDoubleJump(true),
        _textureLeft(textureLeft), _textureRight(textureRight)
    {
        SetLayer(PhysicsManager::PhysicsLayer::PLAYER);
        SetTag(PLAYER);
        SetScale(sf::Vector2f(1.4f, 1.4f));
    }

    void Character::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }

    bool Character::GetHit(Scene &scene, Bullet *bullet) noexcept
    {
        if (!bullet->CanAttack(this))
            return (true);
        _health -= bullet->GetDamage();
        if (_health > 0)
        {
            _healthBar->SetScale(sf::Vector2f(_health / 100.f, .2f));
            return (true);
        }
        scene.RemoveObject(_healthBar);
        scene.RemoveObject(this);
        return (false);
    }

    void Character::GoLeft() noexcept
    {
        if (_isFacingRight)
        {
            _isFacingRight = false;
            SetTexture(_textureLeft);
        }
        AddForce(sf::Vector2f(-_movForce, 0.f));
    }

    void Character::GoRight() noexcept
    {
        if (!_isFacingRight)
        {
            _isFacingRight = true;
            SetTexture(_textureRight);
        }
        AddForce(sf::Vector2f(_movForce, 0.f));
    }

    void Character::Jump() noexcept
    {
        if (_isOnLeftWall)
        {
            AddForce(sf::Vector2f(2.5f * _jumpForce / 3.f, 2.f * -_jumpForce / 4.5f));
            _jumpChrono.Reset();
        }
        else if (_isOnRightWall)
        {
            AddForce(sf::Vector2f(2.5f * -_jumpForce / 3.f, 2.f * -_jumpForce / 4.5f));
            _jumpChrono.Reset();
        }
        else if (_canJump)
        {
            _canJump = false;
            AddForce(sf::Vector2f(0.f, -_jumpForce));
            _jumpChrono.Reset();
        }
        else if (_canDoubleJump && _jumpChrono.IsEnded())
        {
            _canDoubleJump = false;
            AddForce(sf::Vector2f(0.f, -_jumpForce / 1.2f));
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

    void Character::Fall() noexcept
    {
        if (_fallChrono.IsEnded())
        {
            _fallChrono.Reset();
            AddForce(sf::Vector2f(0.f, _jumpForce));
        }
    }

    void Character::FireInternal(Scene &scene, std::unique_ptr<Gun> &gun) noexcept
    {
        std::unique_ptr<Bullet> bullet = gun->Fire(this);
        if (bullet == nullptr)
            return;
        sf::Vector2f pos = GetPosition();
        bullet->SetPosition(sf::Vector2f(pos.x + ((_isFacingRight) ? (55.f) : (-55.f)), pos.y));
        if (!_isFacingRight)
            bullet->InvertVelocity();
        scene.AddObject(std::move(bullet));
    }

    void Character::SetOnLeftWall(bool value) noexcept
    {
        _isOnLeftWall = value;
    }

    void Character::SetOnRightWall(bool value) noexcept
    {
        _isOnRightWall = value;
    }

    void Character::SetCanDoubleJump(bool value) noexcept
    {
        _canDoubleJump = value;
    }

    void Character::SetCanJump(bool value) noexcept
    {
        _canJump = value;
    }
}
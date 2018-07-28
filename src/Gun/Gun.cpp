#include "Gun.hpp"

namespace feg
{
    Gun::Gun(const sf::Texture &texture, int reloadTime, int recoil, int damage, float speed,
        float size, const sf::Color &color, float drag, bool haveGravity) noexcept
        : _texture(texture), _reloadTime(reloadTime), _recoil(recoil), _damage(damage), _speed(speed),
            _size(size), _color(color), _drag(drag), _haveGravity(haveGravity)
    { }

    std::unique_ptr<Bullet> Gun::Fire() noexcept
    {
        if (!_reloadTime.IsEnded())
            return (nullptr);
        _reloadTime.Reset();
        std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(_texture, _damage, _recoil);
        bullet->SetColor(_color)
              ->SetTag(GameObject::BULLET)
              ->SetScale(sf::Vector2f(_size, _size));
        bullet->SetHasGravity(_haveGravity);
        bullet->SetLinearDrag(_drag);
        bullet->AddForce(sf::Vector2f(_speed, 0.f));
        return (bullet);
    }
}
#include "Gun.hpp"

namespace feg
{
    Gun::Gun(const sf::Texture &texture) noexcept
        : _texture(texture)
    { }

    std::unique_ptr<Bullet> Gun::Fire() const noexcept
    {
        std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(_texture);
        bullet->SetColor(sf::Color(0.f, 0.f, 0.f))
              ->SetLayer(PhysicsManager::NOCOLLISION);
        return (bullet);
    }
}
#include "Handgun.hpp"

namespace feg
{
    Handgun::Handgun(TextureManager &tm)
        : Gun(tm.GetTexture("res/WhiteCircle.png"), 1000)
    { }

    std::unique_ptr<Bullet> Handgun::Fire() noexcept
    {
        if (!_reloadTime.IsEnded())
            return (nullptr);
        _reloadTime.Reset();
        std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(_texture);
        bullet->SetColor(sf::Color(0.f, 0.f, 0.f));
        bullet->AddForce(sf::Vector2f(20.f, 0.f));
        return (bullet);
    }
}
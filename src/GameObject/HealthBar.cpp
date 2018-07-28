#include "HealthBar.hpp"

namespace feg
{
    HealthBar::HealthBar(const sf::Texture &texture) noexcept
        : GameObject(texture)
    {
        this->SetLayer(PhysicsManager::NOCOLLISION)->SetScale(sf::Vector2f(1.f, .2f));
    }
}
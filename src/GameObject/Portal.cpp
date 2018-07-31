#include "Portal.hpp"

namespace feg
{
    Portal::Portal(const sf::Texture &texture) noexcept
        : GameObject(texture)
    { }

    PortalEntrance::PortalEntrance(const sf::Texture &texture) noexcept
        : Portal(texture)
    {
        SetTag(PORTAL);
    }

    PortalExit::PortalExit(const sf::Texture &texture) noexcept
        : Portal(texture)
    {
        SetLayer(PhysicsManager::NOCOLLISION);
    }
}
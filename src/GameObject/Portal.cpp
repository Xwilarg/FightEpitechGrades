#include "Portal.hpp"

namespace feg
{
    Portal::Portal(const sf::Texture &texture) noexcept
        : GameObject(texture)
    { }

    PortalEntrance::PortalEntrance(const sf::Texture &texture) noexcept
        : Portal(texture), _exit(nullptr)
    {
        SetTag(PORTAL);
    }

    PortalEntrance *PortalEntrance::SetExit(PortalExit *exit) noexcept
    {
        _exit = exit;
        return (this);
    }

    const PortalExit *PortalEntrance::GetExit() const noexcept
    {
        return (_exit);
    }

    PortalExit::PortalExit(const sf::Texture &texture) noexcept
        : Portal(texture)
    {
        SetLayer(PhysicsManager::NOCOLLISION);
    }
}
#ifndef PORTAL_HPP_
# define PORTAL_HPP_

# include "GameObject.hpp"

namespace feg
{
    class Portal : public GameObject
    {
    public:
        ~Portal() noexcept = default;

    protected:
        Portal(const sf::Texture &texture) noexcept;
    };

    class PortalEntrance final : public Portal
    {
    public:
        PortalEntrance(const sf::Texture &texture) noexcept;
        ~PortalEntrance() noexcept = default;
    };

    class PortalExit final : public Portal
    {
    public:
        PortalExit(const sf::Texture &texture) noexcept;
        ~PortalExit() noexcept = default;
    };
}

#endif // !PORTAL_HPP_
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

    class PortalExit final : public Portal
    {
    public:
        PortalExit(const sf::Texture &texture) noexcept;
        ~PortalExit() noexcept = default;
    };

    class PortalEntrance final : public Portal
    {
    public:
        PortalEntrance(const sf::Texture &texture) noexcept;
        ~PortalEntrance() noexcept = default;
        PortalEntrance *SetExit(PortalExit *exit) noexcept;
        const PortalExit *GetExit() const noexcept;

    private:
        PortalExit *_exit;
    };
}

#endif // !PORTAL_HPP_
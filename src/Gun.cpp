#include "Gun.hpp"

namespace feg
{
    Gun::Gun(const sf::Texture &texture) noexcept
        : _texture(texture)
    { }

    std::unique_ptr<Bullet> Gun::Fire() const noexcept
    {
        return (std::make_unique<Bullet>(_texture));
    }
}
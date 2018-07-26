#include "Gun.hpp"

namespace feg
{
    Gun::Gun(const sf::Texture &texture) noexcept
        : _texture(texture)
    { }

    const sf::Texture &Gun::Fire() const noexcept
    {
        return (_texture);
    }
}
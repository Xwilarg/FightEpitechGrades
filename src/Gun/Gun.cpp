#include "Gun.hpp"

namespace feg
{
    Gun::Gun(const sf::Texture &texture, int reloadTime) noexcept
        : _texture(texture), _reloadTime(reloadTime)
    { }
}
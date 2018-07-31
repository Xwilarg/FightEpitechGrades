#include "Crate.hpp"

namespace feg
{
    Crate::Crate(const sf::Texture &texture) noexcept
        : MovableGameObject(texture)
    {
        SetTag(GameObject::PROP);
    }
}
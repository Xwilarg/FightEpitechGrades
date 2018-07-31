#include "Crate.hpp"

namespace feg
{
    Crate::Crate(const sf::Texture &texture) noexcept
        : MovableGameObject(texture)
    {
        SetTag(GameObject::PROP);
        SetScale(sf::Vector2f(.9f, .9f));
    }
}
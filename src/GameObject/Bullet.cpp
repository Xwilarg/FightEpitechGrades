#include "Bullet.hpp"

namespace feg
{
    Bullet::Bullet(const sf::Texture &texture) noexcept
        : MovableGameObject(texture)
    { }

    void Bullet::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }
}
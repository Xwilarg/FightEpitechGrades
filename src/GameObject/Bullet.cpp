#include "Bullet.hpp"

namespace feg
{
    Bullet::Bullet(const sf::Texture &texture, int damage, float recoil) noexcept
        : MovableGameObject(texture), _damage(damage), _recoil(recoil)
    {
        this->SetLayer(PhysicsManager::BULLET);
    }

    void Bullet::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }
}
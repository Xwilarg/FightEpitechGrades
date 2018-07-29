#include "Bullet.hpp"

namespace feg
{
    Bullet::Bullet(const sf::Texture &texture, Character *c, int damage, float recoil) noexcept
        : MovableGameObject(texture), _damage(damage), _recoil(recoil),
        _launcher(c), _invisibilityChrono(500)
    {
        this->SetLayer(PhysicsManager::BULLET);
    }

    void Bullet::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
    }

    bool Bullet::CanAttack(Character *target) const noexcept
    {
        return (!(target == _launcher && !_invisibilityChrono.IsEnded()));
    }
}
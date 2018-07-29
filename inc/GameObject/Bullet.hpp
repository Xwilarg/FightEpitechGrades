#ifndef BULLET_HPP_
# define BULLET_HPP_

# include "MovableGameObject.hpp"
# include "Chrono.hpp"

namespace feg
{
    class Character;

    class Bullet final : public MovableGameObject
    {
    public:
        Bullet(const sf::Texture &texture, Character *c, int damage, float recoil) noexcept;
        ~Bullet() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept;
        int GetDamage() const noexcept { return (_damage); }
        float GetRecoil() const noexcept { return (_recoil); }
        bool CanAttack(Character *target) const noexcept;

    private:
        const int _damage;
        const float _recoil;
        const Character *_launcher;
        Chrono _invisibilityChrono;
    };
}

#endif // !BULLET_HPP_
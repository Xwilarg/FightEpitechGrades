#ifndef BULLET_HPP_
# define BULLET_HPP_

# include "MovableGameObject.hpp"

namespace feg
{
    class Bullet final : public MovableGameObject
    {
    public:
        Bullet(const sf::Texture &texture, int damage, float recoil) noexcept;
        ~Bullet() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept;
        int GetDamage() const noexcept { return (_damage); }
        float GetRecoil() const noexcept { return (_recoil); }

    private:
        const int _damage;
        const float _recoil;
    };
}

#endif // !BULLET_HPP_
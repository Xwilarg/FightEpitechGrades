#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "MovableGameObject.hpp"
# include "Handgun.hpp"
# include "Machinegun.hpp"

namespace feg
{
    class HealthBar;

    class Character : public MovableGameObject
    {
    public:
        Character(const sf::Texture &texture, ResourcesManager &tm, Scene &scene) noexcept;
        ~Character() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;
        void GetHit(Scene &scene, Bullet *bullet) noexcept;

    protected:
        void GoLeft() noexcept;
        void GoRight() noexcept;
        void Jump() noexcept;
        void Fire1(Scene &scene) noexcept;
        void Fire2(Scene &scene) noexcept;

    private:
        void FireInternal(Scene &scene, Gun &gun) noexcept;
        Handgun _weapon1;
        Machinegun _weapon2;
        const float _movForce;
        const float _jumpForce;
        bool _isFacingRight;
        int _health;
        Chrono _jumpChrono;
        HealthBar *_healthBar;
    };
}

#endif // !CHARACTER_HPP_
#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "MovableGameObject.hpp"
# include "Handgun.hpp"
# include "Machinegun.hpp"
# include "MineLauncher.hpp"

namespace feg
{
    class HealthBar;

    class Character : public MovableGameObject
    {
    public:
        Character(const sf::Texture &texture, ResourcesManager &tm, Scene &scene,
        std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept;
        ~Character() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;
        void GetHit(Scene &scene, Bullet *bullet) noexcept;
        void SetOnLeftWall(bool value) noexcept;
        void SetOnRightWall(bool value) noexcept;
        void SetCanJump(bool value) noexcept;
        void SetCanDoubleJump(bool value) noexcept;

    protected:
        void GoLeft() noexcept;
        void GoRight() noexcept;
        void Jump() noexcept;
        void Fire1(Scene &scene) noexcept;
        void Fire2(Scene &scene) noexcept;
        void Fall() noexcept;

    private:
        void FireInternal(Scene &scene, std::unique_ptr<Gun> &gun) noexcept;
        std::unique_ptr<Gun> _weapon1;
        std::unique_ptr<Gun> _weapon2;
        const float _movForce;
        const float _jumpForce;
        bool _isFacingRight;
        int _health;
        Chrono _jumpChrono;
        Chrono _fallChrono;
        HealthBar *_healthBar;
        bool _isOnLeftWall, _isOnRightWall;
        bool _canJump, _canDoubleJump;
    };
}

#endif // !CHARACTER_HPP_
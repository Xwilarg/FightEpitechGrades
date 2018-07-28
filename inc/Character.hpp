#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "MovableGameObject.hpp"
# include "Handgun.hpp"

namespace feg
{
    class Character : public MovableGameObject
    {
    public:
        Character(const sf::Texture &texture, TextureManager &tm) noexcept;
        ~Character() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;

    protected:
        void GoLeft() noexcept;
        void GoRight() noexcept;
        void Jump() noexcept;
        void Fire(Scene &scene) noexcept;

    private:
        Handgun _weapon;
        const float _movForce;
        const float _jumpForce;
        bool _isFacingRight;
        int _health;
        Chrono _jumpChrono;
    };
}

#endif // !CHARACTER_HPP_
#ifndef GUN_HPP_
# define GUN_HPP_

# include <memory>
# include "Bullet.hpp"
# include "Chrono.hpp"

namespace feg
{
    class Character;

    class Gun
    {
    public:
        Gun(const sf::Texture &texture, int reloadTime, int recoil, int damage, float speed,
            float size, const sf::Color &color, float drag, bool haveGravity) noexcept;
        virtual ~Gun() noexcept = default;
        std::unique_ptr<Bullet> Fire(Character *c) noexcept;

    protected:
        const sf::Texture &_texture;
        Chrono _reloadTime;
        const int _recoil;
        const int _damage;
        const float _speed;
        const float _size;
        const sf::Color _color;
        const float _drag;
        const bool _haveGravity;
    };
}

#endif // !GUN_HPP_
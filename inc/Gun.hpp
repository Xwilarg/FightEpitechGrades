#ifndef GUN_HPP_
# define GUN_HPP_

# include <memory>
# include "Bullet.hpp"
# include "Chrono.hpp"

namespace feg
{
    class Gun
    {
    public:
        Gun(const sf::Texture &texture, int reloadTime) noexcept;
        virtual ~Gun() noexcept = default;
        virtual std::unique_ptr<Bullet> Fire() noexcept = 0;

    protected:
        const sf::Texture &_texture;
        Chrono _reloadTime;
    };
}

#endif // !GUN_HPP_
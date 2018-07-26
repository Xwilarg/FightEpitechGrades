#ifndef GUN_HPP_
# define GUN_HPP_

# include <memory>
# include "Bullet.hpp"
# include "TextureManager.hpp"

namespace feg
{
    class Gun
    {
    public:
        Gun(const sf::Texture &texture) noexcept;
        virtual ~Gun() noexcept = default;
        const sf::Texture &Fire() const noexcept;

    private:
        const sf::Texture &_texture;
    };

    class Handgun final : public Gun
    {
    public:
        Handgun(TextureManager &tm)
            : Gun(tm.GetTexture("res/WhiteCircle.png"))
        { }
        ~Handgun() noexcept = default;
    };
}

#endif // !GUN_HPP_
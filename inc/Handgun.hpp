#ifndef HANDGUN_HPP_
# define HANDGUN_HPP_

# include "Gun.hpp"
# include "TextureManager.hpp"

namespace feg
{
    class Handgun final : public Gun
    {
    public:
        Handgun(TextureManager &tm);
        ~Handgun() noexcept override = default;
        std::unique_ptr<Bullet> Fire() noexcept;
    };
}

#endif // !HANDGUN_HPP_
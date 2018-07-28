#ifndef MACHINEGUN_HPP_
# define MACHINEGUN_HPP_

# include "Gun.hpp"
# include "TextureManager.hpp"

namespace feg
{
    class Machinegun final : public Gun
    {
    public:
        Machinegun(TextureManager &tm);
        ~Machinegun() noexcept override = default;
    };
}

#endif // !MACHINEGUN_HPP_
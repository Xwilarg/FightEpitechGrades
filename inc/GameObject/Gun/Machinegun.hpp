#ifndef MACHINEGUN_HPP_
# define MACHINEGUN_HPP_

# include "Gun.hpp"
# include "ResourcesManager.hpp"

namespace feg
{
    class Machinegun final : public Gun
    {
    public:
        Machinegun(ResourcesManager &tm);
        ~Machinegun() noexcept override = default;
    };
}

#endif // !MACHINEGUN_HPP_
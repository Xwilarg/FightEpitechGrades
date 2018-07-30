#ifndef HANDGUN_HPP_
# define HANDGUN_HPP_

# include "Gun.hpp"
# include "ResourcesManager.hpp"

namespace feg
{
    class Handgun final : public Gun
    {
    public:
        Handgun(ResourcesManager &tm);
        ~Handgun() noexcept = default;
    };
}

#endif // !HANDGUN_HPP_
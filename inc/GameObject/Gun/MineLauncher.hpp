#ifndef MINELAUNCHER_HPP_
# define MINELAUNCHER_HPP_

# include "Gun.hpp"
# include "ResourcesManager.hpp"

namespace feg
{
    class MineLauncher final : public Gun
    {
    public:
        MineLauncher(ResourcesManager &tm);
        ~MineLauncher() noexcept = default;
    };
}

#endif // !MINELAUNCHER_HPP_
#ifndef HEALTHBAR_HPP_
# define HEALTHBAR_HPP_

#include "Character.hpp"

namespace feg
{
    class HealthBar : public GameObject
    {
    public:
        HealthBar(const sf::Texture &texture) noexcept;
        ~HealthBar() noexcept = default;
    };
}

#endif // !HEALTHBAR_HPP_
#ifndef CRATE_HPP_
# define CRATE_HPP_

# include "MovableGameObject.hpp"

namespace feg
{
    class Crate final : public MovableGameObject
    {
    public:
        Crate(const sf::Texture &texture) noexcept;
        ~Crate() noexcept override = default;
    };
}

#endif // !CRATE_HPP
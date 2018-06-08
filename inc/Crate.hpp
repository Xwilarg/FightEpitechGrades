#ifndef CRATE_HPP_
# define CRATE_HPP_

# include "MovingGameObject.hpp"

namespace feg
{
    class Crate : public MovingGameObject
    {
    public:
        ~Crate() noexcept override = default;
    };
}

#endif // !CRATE_HPP
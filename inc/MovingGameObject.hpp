#ifndef MOVINGGAMEOBJECT_HPP_
# define MOVINGGAMEOBJECT_HPP_

# include "GameObject.hpp"

namespace feg
{
    class MovingGameObject : public GameObject
    {
    public:
        ~MovingGameObject() noexcept override = default;
    };
}

#endif // !MOVINGGAMEOBJECT_HPP_
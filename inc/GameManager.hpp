#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include "ResourcesManager.hpp"
# include "PhysicsManager.hpp"

namespace feg
{
    struct GameManager
    {
        PhysicsManager pm;
        ResourcesManager rm;
    };
}

#endif // !GAMEMANAGER_HPP_
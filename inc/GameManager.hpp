#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include "TextureManager.hpp"
# include "PhysicsManager.hpp"

namespace feg
{
    struct GameManager
    {
        PhysicsManager pm;
        TextureManager tm;
    };
}

#endif // !GAMEMANAGER_HPP_
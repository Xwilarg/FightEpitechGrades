#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include "ResourcesManager.hpp"
# include "PhysicsManager.hpp"

namespace feg
{
    struct GameManager
    {
        GameManager(const int xWin, const int yWin)
            : _xWin(xWin), _yWin(yWin), pm(), rm()
        { }

        const int _xWin, _yWin;
        PhysicsManager pm;
        ResourcesManager rm;
    };
}

#endif // !GAMEMANAGER_HPP_
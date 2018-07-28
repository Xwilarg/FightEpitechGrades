#include "Machinegun.hpp"

namespace feg
{
    Machinegun::Machinegun(ResourcesManager &tm)
        : Gun(tm.GetTexture("res/WhiteCircle.png"), 100, 1, 1, 30.f, .2f, sf::Color::Cyan, 1.f, false)
    { }
}
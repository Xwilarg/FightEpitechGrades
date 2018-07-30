#include "MineLauncher.hpp"

namespace feg
{
    MineLauncher::MineLauncher(ResourcesManager &tm)
        :Gun(tm.GetTexture("res/WhiteCircle.png"), 3000, 20, 25, 30.f, .75f, sf::Color::Blue, 1.05f, true)
    { }
}
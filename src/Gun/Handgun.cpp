#include "Handgun.hpp"

namespace feg
{
    Handgun::Handgun(TextureManager &tm)
        : Gun(tm.GetTexture("res/WhiteCircle.png"), 1000, 10, 20, 40.f, .5f, sf::Color::Red, 1.f, false)
    { }
}
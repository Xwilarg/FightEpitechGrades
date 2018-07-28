#include "Text.hpp"

namespace feg
{
    Text::Text(const sf::Texture &texture) noexcept
        : ClickableUI(texture)
    { }
}
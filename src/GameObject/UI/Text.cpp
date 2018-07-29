#include "Text.hpp"

namespace feg
{
    Text::Text(const sf::Font &font, std::string &&str) noexcept
        : _text()
    {
        _text.setFont(font);
        _text.setString(std::move(str));
    }

    void Text::Update(Scene &, sf::RenderWindow &window) noexcept
    {
        window.draw(_text);
    }
}
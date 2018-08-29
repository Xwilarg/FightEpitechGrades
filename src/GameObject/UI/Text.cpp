#include "Text.hpp"

namespace feg
{
    Text::Text(const sf::Font &font) noexcept
        : _text()
    {
        _text.setFont(font);
    }

    const sf::Text &Text::GetText() const noexcept
    {
        return (_text);
    }

    Text *Text::SetPosition(sf::Vector2f &&pos) noexcept
    {
        _text.setPosition(std::move(pos));
        return (this);
    }

    Text *Text::SetString(std::string &&str) noexcept
    {
        _text.setString(std::move(str));
        return (this);
    }

    Text *Text::SetString(const std::string &str) noexcept
    {
        _text.setString(str);
        return (this);
    }

    Text *Text::SetColor(const sf::Color &color) noexcept
    {
        _text.setFillColor(color);
        return (this);
    }

    Text *Text::SetSize(unsigned int size) noexcept
    {
        _text.setCharacterSize(size);
        return (this);
    }
}
#include "Switch.hpp"

namespace feg
{
    Switch::Switch(const sf::Texture &texture) noexcept
        : ClickableUI(texture), _state(false)
    { }

    void Switch::Click() noexcept
    {
        _state = !_state;
        if (_state)
            SetColor(sf::Color::Green);
        else
            SetColor(sf::Color::Red);
    }
}
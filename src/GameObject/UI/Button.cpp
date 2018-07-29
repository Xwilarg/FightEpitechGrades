#include "Button.hpp"

namespace feg
{
    Button::Button(const sf::Texture &texture) noexcept
        : ClickableUI(texture), _toCall(nullptr)
    { }

    void Button::Click() noexcept
    {
        _toCall();
    }

    Button *Button::SetFunction(std::function<void()> &&func)
    {
        _toCall = std::move(func);
        return (this);
    }
}
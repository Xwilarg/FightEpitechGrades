#ifndef BUTTON_HPP_
# define BUTTON_HPP_

# include <functional>
# include "UI/ClickableUI.hpp"

namespace feg
{
    class Button : public ClickableUI
    {
    public:
        Button(const sf::Texture &texture) noexcept;
        ~Button() noexcept = default;
        void Click() noexcept override;
        Button *SetFunction(std::function<void()> &&func);

    private:
        std::function<void()> _toCall;
    };
}

#endif // !SWITCH
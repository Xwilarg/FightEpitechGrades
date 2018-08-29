#ifndef SWITCH_HPP_
# define SWITCH_HPP_

# include "UI/ClickableUI.hpp"

namespace feg
{
    class Switch : public ClickableUI
    {
    public:
        Switch(const sf::Texture &texture) noexcept;
        ~Switch() noexcept = default;
        void Click() noexcept override;

    private:
        bool _state;
    };
}

#endif // !SWITCH_HPP_
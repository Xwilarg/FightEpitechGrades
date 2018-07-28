#ifndef TEXT_HPP_
# define TEXT_HPP_

# include "ClickableUI.hpp"

namespace feg
{
    class Text : public ClickableUI
    {
    public:
        Text(const sf::Texture &texture) noexcept;
        ~Text() noexcept = default;
    };
}

#endif // !TEXT_HPP_
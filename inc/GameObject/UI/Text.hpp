#ifndef TEXT_HPP_
# define TEXT_HPP_

# include "Drawable.hpp"

namespace feg
{
    class Text final : public Drawable
    {
    public:
        Text(const sf::Font &font) noexcept;
        ~Text() noexcept = default;
        const sf::Text &GetText() const noexcept;
        Text *SetPosition(sf::Vector2f &&pos) noexcept;
        Text *SetString(std::string &&str) noexcept;
        Text *SetString(const std::string &str) noexcept;
        Text *SetColor(const sf::Color &color) noexcept;
        Text *SetSize(unsigned int size) noexcept;

    private:
        sf::Text _text;
    };
}

#endif // !TEXT_HPP_
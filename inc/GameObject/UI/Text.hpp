#ifndef TEXT_HPP_
# define TEXT_HPP_

# include "Drawable.hpp"

namespace feg
{
    class Text : public Drawable
    {
    public:
        Text(const sf::Font &font, std::string &&str) noexcept;
        ~Text() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;

    private:
        sf::Text _text;
    };
}

#endif // !TEXT_HPP_
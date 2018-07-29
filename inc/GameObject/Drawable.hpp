#ifndef DRAWABLE_HPP_
# define DRAWABLE_HPP_

# include <SFML/Graphics.hpp>

namespace feg
{
    class Drawable
    {
    public:
        virtual ~Drawable() noexcept = default;
        template <typename T>
        void Draw(sf::RenderWindow &window, const T &toDraw)
        {
            window.draw(toDraw);
        }
        enum Type
        {
            GAMEOBJECT,
            TEXT
        };
        virtual Type GetType() const noexcept = 0;
    };
}

#endif // !DRAWABLE_HPP_
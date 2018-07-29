#ifndef DRAWABLE_HPP_
# define DRAWABLE_HPP_

# include <SFML/Graphics.hpp>

namespace feg
{
    class Scene;

    class Drawable
    {
    public:
        virtual ~Drawable() noexcept = default;
        virtual void Update(Scene &scene, sf::RenderWindow &window) noexcept = 0;
    };
}

#endif // !DRAWABLE_HPP_
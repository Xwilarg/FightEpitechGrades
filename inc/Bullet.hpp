#ifndef BULLET_HPP_
# define BULLET_HPP_

# include "MovableGameObject.hpp"

namespace feg
{
    class Bullet final : public MovableGameObject
    {
    public:
        Bullet(const sf::Texture &texture) noexcept;
        ~Bullet() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept;
    };
}

#endif // !BULLET_HPP_
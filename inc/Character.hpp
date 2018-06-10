#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "MovableGameObject.hpp"

namespace feg
{
    class Character : public MovableGameObject
    {
    public:
        Character(const sf::Texture &texture) noexcept;
        ~Character() noexcept = default;
        void Update(const Scene &scene, sf::RenderWindow &window) noexcept override;

    protected:
        void GoLeft() noexcept;
        void GoRight() noexcept;
        void Jump() noexcept;

    private:
        const float _movForce;
        const float _jumpForce;
    };
}

#endif // !CHARACTER_HPP_
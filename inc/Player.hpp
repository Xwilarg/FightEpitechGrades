#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "MovableGameObject.hpp"

namespace feg
{
    class Player final : public MovableGameObject
    {
    public:
        struct PlayerInput
        {
            PlayerInput(sf::Keyboard::Key left, sf::Keyboard::Key right)
                : _left(left), _right(right)
            { }
            sf::Keyboard::Key _left;
            sf::Keyboard::Key _right;
        };
        Player(const sf::Texture &texture, const PlayerInput &input) noexcept;
        void Update(const Scene &scene, sf::RenderWindow &window) noexcept override;

    private:
        PlayerInput _input;
        const float _movForce;
    };
}

#endif // !PLAYER_HPP_
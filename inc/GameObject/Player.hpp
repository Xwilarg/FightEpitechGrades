#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

namespace feg
{
    class Player final : public Character
    {
    public:
        struct PlayerInput
        {
            PlayerInput(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key jump, sf::Keyboard::Key fall,
            sf::Keyboard::Key fire1, sf::Keyboard::Key fire2)
                : _left(left), _right(right), _jump(jump), _fire1(fire1), _fire2(fire2), _fall(fall)
            { }

            sf::Keyboard::Key _left;
            sf::Keyboard::Key _right;
            sf::Keyboard::Key _jump;
            sf::Keyboard::Key _fire1;
            sf::Keyboard::Key _fire2;
            sf::Keyboard::Key _fall;
        };
        Player(const sf::Texture &textureLeft, const sf::Texture &textureRight, ResourcesManager &tm, Scene &scene, const PlayerInput &input,
        std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;

    private:
        PlayerInput _input;
    };
}

#endif // !PLAYER_HPP_
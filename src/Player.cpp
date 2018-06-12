#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &texture, TextureManager &tm, const PlayerInput &input) noexcept
        : Character(texture, tm), _input(input)
    { }

    void Player::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        Character::Update(scene, window);
        if (scene.IsPressed(_input._left))
            GoLeft();
        else if (scene.IsPressed(_input._right))
            GoRight();
        if (scene.IsPressed(_input._jump))
            Jump();
    }
}
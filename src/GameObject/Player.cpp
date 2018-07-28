#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &texture, TextureManager &tm, Scene &scene, const PlayerInput &input) noexcept
        : Character(texture, tm, scene), _input(input)
    { }

    void Player::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        Character::Update(scene, window);
        if (scene.IsPressed(_input._left))
            GoLeft();
        else if (scene.IsPressed(_input._right))
            GoRight();
        if (scene.IsPressed(_input._jump))
            Jump();
        if (scene.IsPressed(_input._fire1))
            Fire1(scene);
        if (scene.IsPressed(_input._fire2))
            Fire2(scene);
    }
}
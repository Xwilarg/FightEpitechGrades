#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &textureLeft, const sf::Texture &textureRight, ResourcesManager &tm, Scene &scene, const PlayerInput &input,
    std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept
        : Character(textureLeft, textureRight, tm, scene, std::move(weapon1), std::move(weapon2)), _input(input)
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
        if (scene.IsPressed(_input._fall))
            Fall();
    }
}
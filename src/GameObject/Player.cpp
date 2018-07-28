#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &texture, ResourcesManager &tm, Scene &scene, const PlayerInput &input) noexcept
        : Character(texture, tm, scene), _input(input)
    {
        SetColor(sf::Color(255.f, 0.f, 0.f));
    }

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
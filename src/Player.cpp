#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &texture, const PlayerInput &input) noexcept
        : MovableGameObject(texture), _input(input),
        _movForce(1.2f), _jumpForce(30.f)
    { }

    void Player::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
        if (scene.IsPressed(_input._left))
            AddForce(sf::Vector2f(-_movForce, 0.f));
        else if (scene.IsPressed(_input._right))
            AddForce(sf::Vector2f(_movForce, 0.f));
        if (IsOnFloor() && scene.IsPressed(_input._jump))
            AddForce(sf::Vector2f(0.f, -_jumpForce));
    }
}
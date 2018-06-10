#include "Player.hpp"
#include "Scene.hpp"

namespace feg
{
    Player::Player(const sf::Texture &texture, const PlayerInput &input) noexcept
        : MovableGameObject(texture), _input(input)
    { }

    void Player::Update(const Scene &scene, sf::RenderWindow &window) noexcept
    {
        MovableGameObject::Update(scene, window);
        if (scene.IsPressed(_input._left))
            ;
    }
}
#include "Ai.hpp"

namespace feg
{
    Ai::Ai(const sf::Texture &texture, TextureManager &tm, Scene &scene) noexcept
        : Character(texture, tm, scene), _target(nullptr)
    { }

    void Ai::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        Character::Update(scene, window);
        if (_target != nullptr)
        {
            if (_target->GetPosition().x < GetPosition().x)
                GoLeft();
            else
                GoRight();
        }
        Jump();
        Fire1(scene);
        Fire2(scene);
    }

    void Ai::SetTarget(const GameObject *target) noexcept
    {
        _target = target;
    }
}
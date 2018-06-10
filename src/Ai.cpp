#include "Ai.hpp"

namespace feg
{
    Ai::Ai(const sf::Texture &texture) noexcept
        : Character(texture), _target(nullptr)
    { }

    void Ai::Update(const Scene &scene, sf::RenderWindow &window) noexcept
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
    }

    void Ai::SetTarget(const GameObject *target) noexcept
    {
        _target = target;
    }
}
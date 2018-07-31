#include "Ai.hpp"

namespace feg
{
    Ai::Ai(const sf::Texture &texture, ResourcesManager &tm, Scene &scene,
    std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept
        : Character(texture, tm, scene, std::move(weapon1), std::move(weapon2)), _target(nullptr)
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
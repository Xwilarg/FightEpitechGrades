#include "Ai.hpp"
#include "Scene.hpp"

namespace feg
{
    Ai::Ai(const sf::Texture &textureLeft, const sf::Texture &textureRight, ResourcesManager &tm, Scene &scene,
    std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept
        : Character(textureLeft, textureRight, tm, scene, std::move(weapon1), std::move(weapon2)), _target(nullptr)
    { }

    void Ai::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        Character::Update(scene, window);
        if (_target != nullptr)
        {
            if (_target->get()->GetPosition().x < GetPosition().x)
                GoLeft();
            else
                GoRight();
        }
        Jump();
        Fire1(scene);
        Fire2(scene);
    }

    void Ai::SetTarget(const std::shared_ptr<Player> *target) noexcept
    {
        _target = target;
    }


    bool Ai::GetHit(Scene &scene, Bullet *bullet) noexcept
    {
        bool isAlive = Character::GetHit(scene, bullet);
        if (!isAlive)
            scene.SpawnAi(*_target);
        return (isAlive);
    }
}
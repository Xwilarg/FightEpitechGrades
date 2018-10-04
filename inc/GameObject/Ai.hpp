#ifndef AI_HPP_
# define AI_HPP_

# include "Character.hpp"
# include "Player.hpp"

namespace feg
{
    class Ai final : public Character
    {
    public:
        Ai(const sf::Texture &textureLeft, const sf::Texture &textureRight, ResourcesManager &tm, Scene &scene,
        std::unique_ptr<Gun> &&weapon1, std::unique_ptr<Gun> &&weapon2) noexcept;
        ~Ai() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;
        void SetTarget(const std::shared_ptr<Player> *target) noexcept;
        bool GetHit(Scene &scene, Bullet *bullet) noexcept override;

    private:
        const std::shared_ptr<Player> *_target;
    };
}

#endif // !AI_HPP_
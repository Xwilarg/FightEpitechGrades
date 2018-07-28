#ifndef AI_HPP_
# define AI_HPP_

# include  "Character.hpp"

namespace feg
{
    class Ai final : public Character
    {
    public:
        Ai(const sf::Texture &texture, TextureManager &tm, Scene &scene) noexcept;
        ~Ai() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;
        void SetTarget(const GameObject *target) noexcept;

    private:
        const GameObject *_target;
    };
}

#endif // !AI_HPP_
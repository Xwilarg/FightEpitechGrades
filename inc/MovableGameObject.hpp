#ifndef MOVABLEGAMEOBJECT_HPP_
# define MOVABLEGAMEOBJECT_HPP_

# include "GameObject.hpp"

namespace feg
{
    class MovableGameObject : public GameObject
    {
    public:
        ~MovableGameObject() noexcept override = default;
        void Update(sf::RenderWindow &window) noexcept override;

    protected:
        MovableGameObject(const sf::Texture &texture) noexcept;

    private:
        bool DoesCollide(const GameObject &go);
        bool DoesAxisCollide(float myPosition, float mySize, float otherPosition, float otherSize) const noexcept;
        sf::Vector2f _linearVelocity;
        float _linearDrag;
    };
}

#endif // !MOVABLEGAMEOBJECT_HPP_
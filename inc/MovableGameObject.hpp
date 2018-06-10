#ifndef MOVABLEGAMEOBJECT_HPP_
# define MOVABLEGAMEOBJECT_HPP_

# include "GameObject.hpp"

namespace feg
{
    class MovableGameObject : public GameObject
    {
    public:
        MovableGameObject(const sf::Texture &texture) noexcept;
        ~MovableGameObject() noexcept override = default;
        void Update(const Scene &scene, sf::RenderWindow &window) noexcept override;

    protected:
        void AddForce(const sf::Vector2f &force);
        bool IsOnFloor() const noexcept { return (_isOnFloor); }

    private:
        bool DoesCollide(const GameObject &go, bool addXVelocity = true, bool addYVelocity = true);
        bool DoesAxisCollide(float myPosition, float mySize, float otherPosition, float otherSize) const noexcept;
        sf::Vector2f _linearVelocity;
        float _linearDrag;
        const float _gravity;
        bool _isOnFloor;
    };
}

#endif // !MOVABLEGAMEOBJECT_HPP_